// cMsgCMD.cpp: implementation of the cMsgCMD class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#ifdef USEDIALOGTRACE
    #include "testengine.h"
#endif

#include "cMsgCMD.h"
#include "cProtocolNet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cMsgCMD::cMsgCMD()
{
    m_iMsgID_l = CMD;
    m_iMsgID_h = 0;
    m_eType = CMD;
}

cMsgCMD::~cMsgCMD()
{

}


////////////////////////////////////////
//       PrepareSend
/*! Prepare message server send text to client
// \param LPCSTR lpsText : text detail
*/
BOOL  cMsgCMD::PrepareSend(LPCSTR lpsText, BYTE byParam1, BYTE byParam2, BYTE byParam3, BYTE byParam4)
{
    CHAR tmpBuff[MAX_STRING_LEN+1];
    
    strncpy(tmpBuff, lpsText, MAX_STRING_LEN);
    m_strText = tmpBuff;

    m_byParam1 = byParam1;
    m_byParam2 = byParam2;
    m_byParam3 = byParam3;
    m_byParam4 = byParam4;
    
    // message len detail
    m_iMsgDetailLen = m_strText.length();
    m_iMsgDetailLen += NUMOFSTRINGS;
    m_iMsgDetailLen += LEN_PARAM1;
    m_iMsgDetailLen += LEN_PARAM2;
    m_iMsgDetailLen += LEN_PARAM3;
    m_iMsgDetailLen += LEN_PARAM4;

    int iMsgIndex = 0;

    // detailed text
    memcpy(&m_byMsgDetail[iMsgIndex], m_strText.c_str(), m_strText.length() ); 
    iMsgIndex += m_strText.length();
    m_byMsgDetail[iMsgIndex] = '\0';
    iMsgIndex++;

    // param 1
    m_byMsgDetail[iMsgIndex] = byParam1;
    iMsgIndex++;
    // param 2
    m_byMsgDetail[iMsgIndex] = byParam2;
    iMsgIndex++;
    // param 3
    m_byMsgDetail[iMsgIndex] = byParam3;
    iMsgIndex++;
    // param 4
    m_byMsgDetail[iMsgIndex] = byParam4;
    iMsgIndex++;
    
    
    m_bMsgReady = TRUE;
    
    return TRUE;
}


////////////////////////////////////////
//       PrepareSend
/*! Prepare a command using only 2 parameters
// \param BYTE byParam1 : 
// \param BYTE byParam2 : 
*/
BOOL cMsgCMD::PrepareSend(BYTE byParam1, BYTE byParam2)
{
    m_byParam1 = byParam1;
    m_byParam2 = byParam2;

    m_byParam3 = cProtocolNet::PARAM_NOTUSED;
    m_byParam4 = cProtocolNet::PARAM_NOTUSED;

    // message len detail
    m_iMsgDetailLen = 0;
    m_iMsgDetailLen += NUMOFSTRINGS;
    m_iMsgDetailLen += LEN_PARAM1;
    m_iMsgDetailLen += LEN_PARAM2;
    m_iMsgDetailLen += LEN_PARAM3;
    m_iMsgDetailLen += LEN_PARAM4;

    int iMsgIndex = 0;

    // detailed text
    m_byMsgDetail[iMsgIndex] = '\0';
    iMsgIndex++;

    // param 1
    m_byMsgDetail[iMsgIndex] = m_byParam1;
    iMsgIndex++;
    // param 2
    m_byMsgDetail[iMsgIndex] = m_byParam2;
    iMsgIndex++;
    // param 3
    m_byMsgDetail[iMsgIndex] = m_byParam3;
    iMsgIndex++;
    // param 4
    m_byMsgDetail[iMsgIndex] = m_byParam4;
    iMsgIndex++;
    
    m_bMsgReady = TRUE;
    
    return m_bMsgReady;
}


////////////////////////////////////////
//       BuildOnRec
/*! Build the message from received buffer
// \param BYTE* pBuff : buffer received (the position is on detail len)
// \param int iBuffLen : len of the received buffer
*/
BOOL  cMsgCMD::BuildOnRec(BYTE* pBuff, int iBuffLen)
{
    CHAR tmpBuff[MAX_MSG_LEN];

    int iIndex = 0;

    // detail len
    m_iMsgDetailLen = pBuff[iIndex];
    iIndex++;
    m_iMsgDetailLen += pBuff[iIndex] << 8;
    iIndex++;
    
    // text
    int iIxStartRawData = iIndex;
    int iLenRawData = iBuffLen - cProtocolNet::LEN_LEN - LEN_PARAM1 - LEN_PARAM2 - LEN_PARAM3 - LEN_PARAM4;
    ASSERT(iLenRawData <= MAX_STRING_LEN);
    if (iLenRawData > MAX_STRING_LEN)
    {
        iLenRawData = MAX_STRING_LEN;
    }
    
    memset (tmpBuff, 0, MAX_MSG_LEN );
    
    strncpy(tmpBuff, (const char*)&pBuff[iIndex], iLenRawData);
    m_strText = tmpBuff;
    iIndex += m_strText.length() + 1;

    // raw data filed 
    memcpy(m_DetDataField, &pBuff[iIxStartRawData], iLenRawData);

    // param 1
    m_byParam1 = pBuff[iIndex];
    iIndex ++;
    // param 2
    m_byParam2 = pBuff[iIndex];
    iIndex ++;
    // param 3
    m_byParam3 = pBuff[iIndex];
    iIndex ++;
    // param 4
    m_byParam4 = pBuff[iIndex];
    iIndex ++;

    ASSERT(iIndex <= iBuffLen);

    return TRUE;
}

