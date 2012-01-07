// cMsgConnectServer.cpp: implementation of the cMsgConnectServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#ifdef USEDIALOGTRACE
    #include "testengine.h"
#endif

#include "cMsgConnectServer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cMsgConnectServer::cMsgConnectServer()
{
    m_iMsgID_l = CONNECT_SERVER;
    m_iMsgID_h = 0;
    m_eType = CONNECT_SERVER;
    m_iParam1 = 0;
}

cMsgConnectServer::~cMsgConnectServer()
{

}


////////////////////////////////////////
//       PrepareSend
/*! Prepare message connect server 
// \param LPCSTR lpsLogin : login 
// \param LPCSTR lpsPassw : password
// \param LPCSTR lpsPlayer: player name
*/
BOOL  cMsgConnectServer::PrepareSend(LPCSTR lpsLogin, LPCSTR lpsPassw, LPCSTR lpsPlayer, int iParam1)
{
    

    m_strLogin = lpsLogin;
    m_strPassw = lpsPassw;
    m_strPlayerName = lpsPlayer;
    m_iParam1 = iParam1;

   
    m_iMsgDetailLen = m_strLogin.length()  + m_strPassw.length();
    m_iMsgDetailLen += m_strPlayerName.length(); 
    // add 3 null terminated character (3 strings)
    m_iMsgDetailLen += NUMOFSTRINGS;
    // add param 1
    m_iMsgDetailLen += LENPARAM1;
   
    int iMsgIndex = 0;

    // login
    memcpy(&m_byMsgDetail[iMsgIndex], m_strLogin.c_str(), m_strLogin.length() ); 
    iMsgIndex += m_strLogin.length();
    m_byMsgDetail[iMsgIndex] = '\0';
    iMsgIndex++;
    
    // password
    memcpy(&m_byMsgDetail[iMsgIndex], m_strPassw.c_str(), m_strPassw.length() ); 
    iMsgIndex += m_strPassw.length();
    m_byMsgDetail[iMsgIndex] = '\0';
    iMsgIndex++;

    // player name
    memcpy(&m_byMsgDetail[iMsgIndex], m_strPlayerName.c_str(), m_strPlayerName.length() ); 
    iMsgIndex += m_strPlayerName.length();
    m_byMsgDetail[iMsgIndex] = '\0';
    iMsgIndex++;

    // param1 
    m_byMsgDetail[iMsgIndex] = iParam1;
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
BOOL  cMsgConnectServer::BuildOnRec(BYTE* pBuff, int iBuffLen)
{
    CHAR tmpBuff[MAX_MSG_LEN];

    int iIndex = 0;

    // detail len
    m_iMsgDetailLen = pBuff[iIndex];
    iIndex++;
    m_iMsgDetailLen += pBuff[iIndex] << 8;
    iIndex++;
    
    // login
    memset (tmpBuff, 0, MAX_MSG_LEN );
    strncpy(tmpBuff, (const char*)&pBuff[iIndex], MAX_LOGIN_LEN);
    m_strLogin = tmpBuff;
    iIndex += m_strLogin.length() + 1;

    // password
    memset (tmpBuff, 0, MAX_MSG_LEN );
    strncpy(tmpBuff, (const char*)&pBuff[iIndex], MAX_PASW_LEN);
    m_strPassw = tmpBuff;
    iIndex += m_strPassw.length() + 1;

    // name player
    memset (tmpBuff, 0, MAX_MSG_LEN );
    strncpy(tmpBuff, (const char*)&pBuff[iIndex], MAX_NAME_LEN);
    m_strPlayerName = tmpBuff;
    iIndex += m_strPlayerName.length() + 1;

    // param 1
    m_iParam1 = pBuff[iIndex];
    iIndex ++;

    ASSERT(iIndex <= iBuffLen);

    return TRUE;
}

