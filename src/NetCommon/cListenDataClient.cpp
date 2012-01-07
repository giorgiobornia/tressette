// cListenDataClient.cpp: implementation of the cListenDataClient class.
//
//////////////////////////////////////////////////////////////////////
#include "win_type_global.h"
#include "cListenDataClient.h"
#include "Log.h"
#include "cProtocolNet.h"

#include "MsgQueueServer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


cListenDataClient::cListenDataClient(I_BinderMsg* pVal,  Socket*pS)
{
    m_pSock = pS;
    m_pBinder = pVal;
    m_pConnClient = 0;
    m_bTerminated = FALSE;
    m_hThListen = 0;
}



////////////////////////////////////////
//       ~cListenDataClient
/*! 
*/
cListenDataClient::~cListenDataClient()
{

}


////////////////////////////////////////
//       StopThread
/*! Sto the listen thread
*/
void cListenDataClient::StopThread()
{
    m_bTerminated = TRUE;
    SDL_WaitThread(m_hThListen, NULL);
}


////////////////////////////////////////
//       Run
/*! Run listen thread
*/
void cListenDataClient::Run()
{
    m_hThListen = SDL_CreateThread((LP_FNTHREAD)stath_ListenClient, this);
}



////////////////////////////////////////
//       th_ListenClient
/*! Wait data from client
*/
int  cListenDataClient::th_ListenClient()
{
    ASSERT(m_pConnClient);
    ASSERT(m_pSock);
    ASSERT(m_pBinder);
    ASSERT(m_pConnClient->m_pProto);

    debug->Print(0,"Listen host %s\n", m_pSock->GetHostname() );
    BYTE byBuffer[BUFFLEN];

    m_bTerminated = FALSE;
    while(!m_bTerminated)
    {
        if (m_pSock->WaitForData(1))
        {
            int iLen = m_pSock->Receive(byBuffer, BUFFLEN);
            // data are available
            if ( iLen  > 0 )
            {
                // data received ok
                m_pConnClient->m_pProto->ParseRawMessage(byBuffer, iLen);  
                handleMessage();
            }
            else
            {
                // client is disconnected
                if (!m_bTerminated)
                {
                    m_pBinder->ClientDisconnected( m_pConnClient->GetPlayerId());
                    // disconnected
                    // pay attention on the terminate condition: 
                    // if m_pNetClient stop the
                    // this thread and set m_bTerminated = TRUE, no callback notification is to be used
                    // Why?
                    m_bTerminated = TRUE;
                }
            }
        }
    }

    
    
    return 0;
}


////////////////////////////////////////
//       handleMessage
/*! Analysis of recived message stack
*/
void cListenDataClient::handleMessage()
{
    ASSERT(m_pConnClient->m_pProto);
    ASSERT(m_pBinder);

    cProtocolNet* pProto = m_pConnClient->m_pProto;

    
    cMsgBase* pMsgBase;
    while( pProto->GetNextMsg(&pMsgBase) )
    {
        m_pBinder->AddMsg(pMsgBase, m_pConnClient);
    }

   
}



