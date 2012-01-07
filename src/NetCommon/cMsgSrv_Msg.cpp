// cMsgSrv_Msg.cpp: implementation of the cMsgSrv_Msg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#ifdef USEDIALOGTRACE
    #include "testengine.h"
#endif

#include "cMsgSrv_Msg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cMsgSrv_Msg::cMsgSrv_Msg()
{
    m_iMsgID_l = SRV_MSG;
    m_iMsgID_h = 0;
    m_eType = SRV_MSG;
}

cMsgSrv_Msg::~cMsgSrv_Msg()
{

}


////////////////////////////////////////
//       PrepareSend
/*! Prepare message server send text to client
// \param LPCSTR lpsText : text detail
*/
BOOL  cMsgSrv_Msg::PrepareSend(LPCSTR lpsText, BYTE byParam1, BYTE byParam2)
{
    CHAR tmpBuff[MAX_STRING_LEN+1];
    
    strncpy(tmpBuff, lpsText, MAX_STRING_LEN);
    m_strText = tmpBuff;

    m_byParam1 = byParam1;
    m_byParam2 = byParam2;
    
    // message len detail
    m_iMsgDetailLen = m_strText.length();
    m_iMsgDetailLen += NUMOFSTRINGS;
    m_iMsgDetailLen += LEN_PARAM1;
    m_iMsgDetailLen += LEN_PARAM2;
   
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
    
    
    m_bMsgReady = TRUE;
    
    return TRUE;
}


////////////////////////////////////////
//       BuildOnRec
/*! Build the message from received buffer
// \param BYTE* pBuff : buffer received (the position is on detail len)
// \param int iBuffLen : len of the received buffer
*/
BOOL  cMsgSrv_Msg::BuildOnRec(BYTE* pBuff, int iBuffLen)
{
    ASSERT(MAX_STRING_LEN < MAX_MSG_LEN);
    CHAR tmpBuff[MAX_MSG_LEN];

    int iIndex = 0;

    // detail len
    m_iMsgDetailLen = pBuff[iIndex];
    iIndex++;
    m_iMsgDetailLen += pBuff[iIndex] << 8;
    iIndex++;
    
    // text
    memset (tmpBuff, 0, MAX_MSG_LEN );
    strncpy(tmpBuff, (const char*)&pBuff[iIndex], MAX_STRING_LEN);
    m_strText = tmpBuff;
    iIndex += m_strText.length() + 1;

    // param 1
    m_byParam1 = pBuff[iIndex];
    iIndex ++;

    // param 2
    m_byParam2 = pBuff[iIndex];
    iIndex ++;

    ASSERT(iIndex <= iBuffLen);

    return TRUE;
}

