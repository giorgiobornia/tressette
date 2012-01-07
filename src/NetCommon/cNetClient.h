// cNetClient.h: interface for the cNetClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CNETCLIENT_H__02469B49_81A0_4D9B_BC9C_F92160EA554F__INCLUDED_)
#define AFX_CNETCLIENT_H__02469B49_81A0_4D9B_BC9C_F92160EA554F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "win_type_global.h"
#include "Socket.h"
#include "cListenDataClient.h"
#include "MsgQueueServer.h"
#include "I_BinderMsg.h"

class cProtocolNet;
class cPoolMsg;
class cInvidoHMI;
class cMsgBase;
class cPlayer;
class cTransaction;

//! class cNetClient  
class cNetClient  : public I_BinderMsg
{
    enum
    {
        SERVER = 0,
        PEER = 1
    };
public:
	cNetClient();
	virtual ~cNetClient();

    // result values
    enum eResValComm
    {
        RES_OK = 0,
        ERR_CONN_TIMEOUT,
        ERR_LOGIN
    };

public:
    //! Init
    void  Init(cInvidoHMI* pHmi);
    //! login server
    void  LoginServer(LPCSTR strLogin, LPCSTR strPassw);
    //! disconnect server
    void  Disconnect();
    //! set player info
    void  SetPlayer(cPlayer* pVal){m_pPlayer = pVal;}
    //! connect to the server
    BOOL  Connect(LPCSTR strAddr, int iPort);
    //! polling funcion to process messages in the queue
    void  ProcMsgInQueue();
    //! process a message direct from listening thread
    void  ProcessMsg(cMsgBase*  pMsgBase, ULONG ulID);
    //! logout
    void  Logout();

// I_BinderMsg interface
    //! client is disconnected
    virtual void  ClientDisconnected(ULONG ulID);
    //! add message from player
    virtual void  AddMsg(cMsgBase* pMsgBase, cConnClient* pConnClient);

private:
    void examsRecSeverMsg(cQueueMSG& MsgToProc);
    void examsRecCmd(cQueueMSG& MsgToProc);

private:
    //! server socket object connection
    Socket*         m_pSocketServer;
    //! server connection flag
    BOOL            m_bServerConnected;
    //! player information
    cPlayer*        m_pPlayer;
    //! server listener
    cListenDataClient*    m_pListDataServ;
    //! hmi pointer
    cInvidoHMI*     m_pHmi;
    //! meassage queue
    cQueueMsgServer m_MsgQueue;
    //! server information
    cConnClient*    m_pConnServer;
    //! transaction manager
    cTransaction*   m_pTransMgr;
    
};

#endif // !defined(AFX_CNETCLIENT_H__02469B49_81A0_4D9B_BC9C_F92160EA554F__INCLUDED_)
