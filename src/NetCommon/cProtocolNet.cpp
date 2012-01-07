// cProtocolNet.cpp: implementation of the cProtocolNet class.
//
//////////////////////////////////////////////////////////////////////
#include "win_type_global.h"
#include "cProtocolNet.h"
#include "Socket.h"
#include "Log.h"
#include "cPoolMsg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cProtocolNet::cProtocolNet(Socket* pSock)
{
    m_pSocket = pSock;
    m_iLenBrokenMsg = 0;
    for (int i = 0; i < cMsgBase::NUM_OF_MSG; i++ )
    {
        m_apAllMsgAvail[i] = 0;
    }
    m_pMsgPool = 0;
}

cProtocolNet::~cProtocolNet()
{

}


////////////////////////////////////////
//       Send
/*! Send a message
// \param cMsgBase& oMsg : 
*/
BOOL  cProtocolNet::Send(cMsgBase& oMsg)
{
    ASSERT(m_pSocket);
    BOOL bRes = FALSE;

    // prepare message (id)
    int iMsgIndex = 0;   
    m_bySentMessage[iMsgIndex] = oMsg.GetIDLow();
    iMsgIndex++;
    m_bySentMessage[iMsgIndex] = oMsg.GetIDHigh();
    iMsgIndex++;

    int iDetLen = oMsg.GetDetLen();
    if (iDetLen <= MAX_LEN_DET)
    {
        // message don't need to be splitted
        // sub ids set to 0
        m_bySentMessage[iMsgIndex] = 0;
        iMsgIndex++;
        m_bySentMessage[iMsgIndex] = 0;
        iMsgIndex++;
        
        // len of data details
        // low part of len
        m_bySentMessage[iMsgIndex] = iDetLen ;
        iMsgIndex++;
        //high part of len
        m_bySentMessage[iMsgIndex] = iDetLen >> 8;
        iMsgIndex++;

        // data details
        memcpy(&m_bySentMessage[iMsgIndex], oMsg.GetBuf(), iDetLen);
        iMsgIndex +=  iDetLen;

        // total len of the message
        m_iMsgSentTotalLen =  ID_LEN + SUB_ID_LEN + LEN_LEN + iDetLen + CRC_LEN ;
        // calc crc
        m_bySentMessage[iMsgIndex] = 0xfe;
        iMsgIndex++;
        m_bySentMessage[iMsgIndex] = 0xfe;
        iMsgIndex++;
        
        m_pSocket->Send(m_bySentMessage, m_iMsgSentTotalLen);
    }
    else
    {
        // split the big message in different sub messages
        ASSERT(0);
    }

     

    return bRes;
}




////////////////////////////////////////
//       ParseRawMessage
/*! Process raw received buffer. A message could be broken and the rest is received by the next parse.
// \param BYTE* pByteArrRes : pointer to the received buffer
// \param int iRecBuffLen : len of the received data buffer
*/
BOOL  cProtocolNet::ParseRawMessage(BYTE* pByteArrRes, int iRecBuffLen)
{
    ASSERT(pByteArrRes);
    BOOL bRet = FALSE;
    int idPosHigh;
    
    if(iRecBuffLen < (MAX_BUFFER_RECEIVED - m_iLenBrokenMsg))
    {
        if (m_iLenBrokenMsg > 0)
        {
            // use a broken message
            memcpy(m_byRecMessage, m_byBrokenMessage, m_iLenBrokenMsg);
        }
        memcpy(&m_byRecMessage[m_iLenBrokenMsg], pByteArrRes, iRecBuffLen);
        iRecBuffLen += m_iLenBrokenMsg;
        m_iLenBrokenMsg = 0;
        int iCurrBuffPos = 0;
        
        while (iCurrBuffPos < iRecBuffLen)
        {
            if ( checkBrokenMsg(iCurrBuffPos, iRecBuffLen) )
            {
                // broken message. Ok it was saved, now we can exit
                debug->Print(3, "[ParseRec]: broken message\n");
                break;
            }
            
            // here we have a complete message to be analyzed
            int iDataDetLen = iCurrBuffPos + ID_LEN + SUB_ID_LEN;
            int idPosLow = iCurrBuffPos;
            idPosHigh = idPosLow + 1;
            BOOL bMsgFound = FALSE;

            // need free all type of messages available
            updateAvailMsg(m_apAllMsgAvail);

            cMsgBase* pMsg  = 0;
            for (int i = 0; i < cMsgBase::NUM_OF_MSG; i++ )
            {
                pMsg = m_apAllMsgAvail[i];
                ASSERT(pMsg);
                if (pMsg->CheckType(m_byRecMessage[idPosLow], m_byRecMessage[idPosHigh]) )
                {
                    // message found, build it
                    pMsg->BuildOnRec(&m_byRecMessage[iDataDetLen], iRecBuffLen - iDataDetLen);
                    
                    iCurrBuffPos += pMsg->GetDetLen() + MSG_PCK_LEN; 
                    bMsgFound = TRUE;
                    break;
                }
            }
            ASSERT(bMsgFound); // message should always be recognized
            if (bMsgFound)
            {
                // add reference to mark, the  
                pMsg->AddRef(); 
                // store the recognized message in the queue
                m_deqpRecMsg.push_back(pMsg);
                bRet = TRUE;
            }

        }
    }
    else
    {
        // message too long, ignore it
        ASSERT(0);
    }

    return bRet;
}


////////////////////////////////////////
//       checkBrokenMsg
/*! Check if the received buffer position is a broken message
// \param int iIndex : index to check in the recived buffer
// \param int iBuffTotLen : total lenght of the recived buffer
*/
BOOL cProtocolNet::checkBrokenMsg(int iIndex, int iBuffTotLen)
{
    int iStartIndex = iIndex;
    int iRemBufferLen = iBuffTotLen - iStartIndex;
    int iMsgLEN = MIN_MSG_LEN;
    BOOL bBrokenMsg = FALSE;

    if (iMsgLEN <= iRemBufferLen)
    {
        // msg has reached min lenght
        // calculate total length (min len + detail len)
        iMsgLEN = MIN_MSG_LEN + m_byRecMessage[iIndex + ID_LEN];
        if ( iMsgLEN >   iRemBufferLen )
        {
            bBrokenMsg = TRUE;
            
        }
    }
    else
    {
        // min len not reached
        bBrokenMsg = TRUE;
    }
    if (bBrokenMsg)
    {
        // message is broken
        memcpy(m_byBrokenMessage, &m_byRecMessage[iIndex], iRemBufferLen);
        m_iLenBrokenMsg = iRemBufferLen;
    }
    return bBrokenMsg;
}



////////////////////////////////////////
//       GetNextMsg
/*! Provides the next message recived
// \param cMsgBase* pMsg : pointer to the received message
*/
BOOL  cProtocolNet::GetNextMsg(cMsgBase** ppMsg)
{
    ASSERT(ppMsg);
    BOOL bRet = FALSE;
    int iSize = m_deqpRecMsg.size();
    if (iSize > 0)
    {
        *ppMsg = m_deqpRecMsg.front();
        m_deqpRecMsg.pop_front();
        bRet = TRUE;
    }
    return bRet;
}


////////////////////////////////////////
//       updateAvailMsg
/*! The array have to contain all available messages. 
// \param cMsgBase** m_apAllMsgAvail : 
*/
void cProtocolNet::updateAvailMsg(cMsgBase** ppAllMsgAvail)
{
    ASSERT(ppAllMsgAvail);
    ASSERT(m_pMsgPool);
    cMsgBase* pmsgNew;
    for (int i = 0; i < cMsgBase::NUM_OF_MSG; i++ )
    {
        BOOL bMsgNotAssigned = FALSE;
        if (ppAllMsgAvail[i] == 0)
        {
            bMsgNotAssigned = TRUE;
        }
        else
        {
            // object assigned, check if is relased
            if (ppAllMsgAvail[i]->RefCnt() > 0)
            {
                bMsgNotAssigned = TRUE;
            }
        }
        if (bMsgNotAssigned)
        {
            // message in slot not assigned
            m_pMsgPool->GetPoolMsg(i, &pmsgNew);
            ppAllMsgAvail[i] = pmsgNew;
        }
    }
}


