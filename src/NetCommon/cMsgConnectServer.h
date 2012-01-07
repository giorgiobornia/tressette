// cMsgConnectServer.h: interface for the cMsgConnectServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMSGCONNECTSERVER_H__441F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_)
#define AFX_CMSGCONNECTSERVER_H__441F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cMsgBase.h"

//! class cMsgConnectServer
class cMsgConnectServer  : public  cMsgBase
{
    enum
    {
        NUMOFSTRINGS = 3,
        MAX_MSG_LEN = 1024,
        MAX_LOGIN_LEN = 64,
        MAX_PASW_LEN = 64,
        MAX_NAME_LEN = 64,
        LENPARAM1 = 1
    };
public:
	cMsgConnectServer();
	virtual ~cMsgConnectServer();

    //! build message for send CONNECT_SERVER
    BOOL  PrepareSend(LPCSTR lpsLogin, LPCSTR lpsPassw, LPCSTR lpsPlayer, int iParam1);
    //! build message from  received buffer 
    virtual BOOL BuildOnRec(BYTE* pBuff, int iBuffLen);
    //! provides login
    STRING  GetLogin(){return m_strLogin;}
    //! provides password
    STRING  GetPassw(){return m_strPassw;}
    //! provides player name
    STRING  GetPlayerName(){return m_strPlayerName;}
    //! provides parameter 1
    int     GetParam1(){return m_iParam1;}

private:
    //! login 
    STRING        m_strLogin;
    //! password
    STRING        m_strPassw;
    //! player name
    STRING        m_strPlayerName;
    //! parameter 1
    int           m_iParam1;
    

};

#endif // !defined(AFX_CMSGCONNECTSERVER_H__441F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_)
