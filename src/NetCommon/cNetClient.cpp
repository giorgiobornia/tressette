// cNetClient.cpp: implementation of the cNetClient class.
//
//////////////////////////////////////////////////////////////////////

#include "cNetClient.h"
#include "cProtocolNet.h"
#include "Log.h"
#include "cPlayer.h"
#include "cMsgConnectServer.h"
#include "cPoolMsg.h"
#include "cInvidoHMI.h"
#include "cMsgSrv_Msg.h"
#include "cMsgCMD.h"
#include "cTransaction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


////////////////////////////////////////
//       cNetClient
/*! 
*/
cNetClient::cNetClient()
{
    m_bServerConnected = FALSE;
    m_pPlayer = 0;
    m_pListDataServ = 0;
    m_pHmi = 0;
    m_pSocketServer = 0;
    m_pConnServer = 0;
    m_pTransMgr = 0;
}


////////////////////////////////////////
//       ~cNetClient
/*! 
*/
cNetClient::~cNetClient()
{
 
    delete m_pSocketServer;
    delete m_pTransMgr;
    ASSERT(m_pListDataServ == 0);
    // shutdown SDL_net
	SDLNet_Quit();
    
}


////////////////////////////////////////
//       Init
/*! Initialize the net client 
*/
void cNetClient::Init(cInvidoHMI* pHmi)
{
    // initialize SDL_net
	if(SDLNet_Init()==-1)
	{
		debug->Print(0, "SDLNet_Init: %s\n",SDLNet_GetError());
		return;
	}

    m_pSocketServer = new Socket; 
    m_pTransMgr = new cTransaction;
    
    m_pHmi = pHmi;
}



////////////////////////////////////////
//       Connect
/*! Try to connect  the server
// \param LPCSTR strAddr : server address (e.g. 127.0.0.1)
// \param int iPort : port connected 
*/
BOOL cNetClient::Connect(LPCSTR strAddr, int iPort)
{
    ASSERT(m_pSocketServer);
    m_pSocketServer->Init(strAddr, iPort); 
    ASSERT(!m_bServerConnected);
    if (m_pSocketServer->Connect())
    {
        // clear queue messages
        m_MsgQueue.Init();
        m_bServerConnected = TRUE;
        m_pConnServer = new cConnClient(m_pSocketServer, NULL);
        // create a server listener
        m_pListDataServ = new cListenDataClient(this, m_pSocketServer);
        m_pConnServer->SetId(SERVER);      
        m_pListDataServ->SetConnClient(m_pConnServer);

        // start listen server thread 
        m_pListDataServ->Run(); 
    }
    return m_bServerConnected;
}

////////////////////////////////////////
//       LoginServer
/*! Login into the server
*/
void  cNetClient::LoginServer(LPCSTR strLogin, LPCSTR strPassw)
{
    ASSERT(m_pPlayer);
    
    if (m_bServerConnected)
    {
        // prepare login transaction
        int iTransId = m_pTransMgr->Insert(cTrasDet::LOGIN);

        ASSERT(m_pConnServer);
        cMsgConnectServer  aMsgConnServer;
        aMsgConnServer.PrepareSend(strLogin, strPassw, m_pPlayer->GetName(), iTransId );
        m_pConnServer->m_pProto->Send(aMsgConnServer); 
    }
    else
    {
        debug->Print(0, "Connection with the server not available\n"); 
    }
}


////////////////////////////////////////
//       Logout
/*! Logout on server 
*/
void  cNetClient::Logout()
{
    ASSERT(m_pPlayer);
    
    if (m_bServerConnected)
    {
        // prepare login transaction
        int iTransId = m_pTransMgr->Insert(cTrasDet::LOGOUT);

        ASSERT(m_pConnServer);
        cMsgCMD  aMsgCmd;
        aMsgCmd.PrepareSend(cProtocolNet::CMDMSG_LOGOUT, iTransId );
        m_pConnServer->m_pProto->Send(aMsgCmd); 
    }
    else
    {
        debug->Print(0, "Connection with the server not available\n"); 
    }
}

////////////////////////////////////////
//       Disconnect
/*! Disconnect the communication with the server and stop listening thread
*/
void  cNetClient::Disconnect()
{
    if (m_bServerConnected)
    {
        // TO DO: prepare message bye
        //m_pProtocoll->Prepare_Bye();
        //m_pProtocoll->Send();
        m_bServerConnected = FALSE;
        m_pSocketServer->Disconnect(); 
    }
    if (m_pListDataServ)
    {
        m_pListDataServ->StopThread();
        
        delete m_pListDataServ;
        m_pListDataServ = 0;
    }
    // clear the queue of m_pConnServer
    m_MsgQueue.Reset();
    if (m_pConnServer)
    {
        delete m_pConnServer;
        m_pConnServer = 0;
    }
}


////////////////////////////////////////
//       ProcMsgInQueue
/*! Polling function to process all the messages in the queue
*/
void cNetClient::ProcMsgInQueue()
{
    if (m_bServerConnected)
    {
        // process the queue only if we are connected
        cQueueMSG MsgToProc;
        BOOL bExit = FALSE;
        while (!bExit)
        {
            m_MsgQueue.GetMsgNoSig(&MsgToProc);
            if ( MsgToProc.GetIsValid() )
            {
                // message to process
                cMsgBase::eMsgType eMsgType = MsgToProc.pMsgBase->GetType();  
                if ( eMsgType == cMsgBase::SRV_MSG)
                {
                    examsRecSeverMsg(MsgToProc);
                }
                else if (eMsgType == cMsgBase::CMD)
                {
                    examsRecCmd(MsgToProc);
                }
        
            }
            else
            {
                // no more messages in the queue
                bExit = TRUE;
            }
        }
    }
}


////////////////////////////////////////
//       examsSeverMsg
/*! Exams the message sent by the server (Info, OK, ERR)
// \param cQueueMSG& MsgToProc : message detail
*/
void cNetClient::examsRecSeverMsg(cQueueMSG& MsgToProc)
{
    // downcasting garanted by type id
    cMsgSrv_Msg*pMsgSrv = (cMsgSrv_Msg*)(MsgToProc.pMsgBase);
    int iDet = pMsgSrv->GetParam1();
    int iTransId = pMsgSrv->GetParam2();
    ASSERT(m_pTransMgr);

    if ( iDet == cProtocolNet::SRVMSG_1_INFO)
    {
        // simple information
        STRING strText = pMsgSrv->GetText();
        m_pHmi->Ntf_Net_ServerInfo( strText.c_str()  );
    }
    else if (iDet == cProtocolNet::SRVMSG_1_OK)
    {
        // server transaction terminated with ok
        cTrasDet TrasRes;
        if ( m_pTransMgr->FindTrans(iTransId, &TrasRes)) 
        {
            if (TrasRes.m_eTranType == cTrasDet::LOGIN)
            {
                // login transaction
                STRING strText = pMsgSrv->GetText();
                m_pHmi->Ntf_Net_LoginRes(RES_OK, strText.c_str());
            }
            else if (TrasRes.m_eTranType == cTrasDet::LOGOUT)
            {
                // logout transaction
                STRING strText = pMsgSrv->GetText();
                m_pHmi->Ntf_Net_LogoutRes(RES_OK, strText.c_str());
            }
            else if (TrasRes.m_eTranType == cTrasDet::CMD)
            {
                // command  transaction
                // command ok, do nothing
            }
            else
            {
                // other transaction
                ASSERT(0);// TO DO
            }
            // remove transaction
            m_pTransMgr->RemoveTrans(iTransId);

        }
        else
        {
            // transaction not exist, ignore it
        }
         
    }
    else if (iDet == cProtocolNet::SRVMSG_1_ERROR)
    {
        // server transaction terminated with an error
        cTrasDet TrasRes;
        if ( m_pTransMgr->FindTrans(iTransId, &TrasRes)) 
        {
            if (TrasRes.m_eTranType == cTrasDet::LOGIN)
            {
                // login transaction error
                STRING strText = pMsgSrv->GetText();
                m_pHmi->Ntf_Net_LoginRes(ERR_LOGIN, strText.c_str());
            }
            else
            {
                // other transaction error
                ASSERT(0); // TO DO
            }
        }
    }
}



////////////////////////////////////////
//       examsRecCmd
/*! Exams a received command
// \param cQueueMSG& MsgToProc : message detail
*/
void cNetClient::examsRecCmd(cQueueMSG& MsgToProc)
{
    
    // downcasting garanted by type id
    cMsgCMD*  pMsgCMD = (cMsgCMD*)(MsgToProc.pMsgBase);

    cMsgSrv_Msg  msgResp;
    CHAR Buff[cProtocolNet::MAX_MSG_LEN];

    BYTE byPara1 = pMsgCMD->GetParam1();
    if (byPara1 == cProtocolNet::CMDMSG_NUMOFCONNECTED)
    {
        // number of client connected notification
    }
    else
    {
        ASSERT(0);
    }
}


//////////////////////////////////////////
// notification from listener
//////////////////////////////////////////


////////////////////////////////////////
//       SockDisconnected
/*! Server is disconnected (thread listener notification)
// \param cListenData::eType eVal : type of listener
*/
void  cNetClient::ClientDisconnected(ULONG ulID)
{
    ASSERT(m_pHmi);
    if (ulID == SERVER)
    {
        // server is disconnected
        m_bServerConnected = FALSE;
        m_pHmi->Ntf_Net_ServerDiscon();
    }
}


////////////////////////////////////////
//       AddMsg
/*! Add a message in the queue
// \param cMsgBase* pMsgBase : 
// \param cConnClient* pConClient : 
*/
void  cNetClient::AddMsg(cMsgBase* pMsgBase, cConnClient* pConClient)
{
    cQueueMSG Msg(pConClient, pMsgBase);

    m_MsgQueue.PutMsg(Msg);
}


// ******** obsolete notification *********

////////////////////////////////////////
//       ProcessMsg
/*! [OBSOLETE-use ProcMsgInQueue]Process a received message
// \param cMsgBase*  pMsgBase : Base message received
// \param cListenData::eType eVal : type of socket connection
*/
void  cNetClient::ProcessMsg(cMsgBase*  pMsgBase, ULONG ulID)
{
    ASSERT(m_pHmi);
    cMsgSrv_Msg* pMsgSrv = 0;
    cMsgCMD* pCmd = 0;
    STRING strText;

    if (ulID == SERVER)
    {
        // using type, advantages:
        // No RTTI and performances related to function GetType()
        // This is the way used by QT framework
        
        /*
        // message from server
        cMsgBase::eMsgType eMsgType =  pMsgBase->GetType() ;
        switch(eMsgType)
        {
            case cMsgBase::CONNECT_SERVER:
                ASSERT(0); // invalid command
                break;

            case cMsgBase::SRV_MSG:
                // message from server
                pMsgSrv = (cMsgSrv_Msg*)(pMsgBase); // we need /GR option for this
                //pMsgSrv = pMsgBase;
                if (pMsgSrv->GetParam1() == cProtocolNet::SRVMSG_1_INFO)
                {
                    strText = pMsgSrv->GetText();
                    m_pHmi->Ntf_Net_ServerInfo( strText.c_str()  );
                }
                break;

            default:
                ASSERT(0);
                break;
        }
        */
        
        
        // using dynamic_cast has the drawback: 
        //  1) RTTI has to be enabled  
        //  2) May performance are not predictable
        pMsgSrv = dynamic_cast<cMsgSrv_Msg*>(pMsgBase);
        if (pMsgSrv)
        {
            // text message from server
            if (pMsgSrv->GetParam1() == cProtocolNet::SRVMSG_1_INFO)
            {
                strText = pMsgSrv->GetText();
                m_pHmi->Ntf_Net_ServerInfo( strText.c_str()  );
            }
            else if (pMsgSrv->GetParam1() == cProtocolNet::SRVMSG_1_OK)
            {
                // TO DO
                ASSERT(0);
            }
            else if (pMsgSrv->GetParam1() == cProtocolNet::SRVMSG_1_ERROR)
            {
                // TO DO
                ASSERT(0);
            }
            else
            {
                ASSERT(0);
            }
        }
        else
        {
            // other message
            cMsgCMD* pCmd = dynamic_cast<cMsgCMD*>(pMsgBase);
            if (pCmd)
            {
                // command message
            }
            else
            {
                // all other message from server are ignored
            }
        }
        
    
        // message processed, make it free
        pMsgBase->Release();
    }
}


