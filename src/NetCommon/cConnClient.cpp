// cConnClient.cpp: implementation of the cConnClient class.
//
//////////////////////////////////////////////////////////////////////
#include "win_type_global.h"
#include "cConnClient.h"
#include "Log.h"
#include "cProtocolNet.h"
#include "cListenDataClient.h"
#include "cPoolMsg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



////////////////////////////////////////
//       cConnClient
/*! Constructor 
// \param Socket* pVal : 
// \param cListenDataClient* pListen : 
*/
cConnClient::cConnClient(Socket* pVal, cListenDataClient* pListen)
{
    // client has a protocol in order to have multiple send and receive buffer.
    // Because multithreading the protocol may be used in the same time for different user
    // For each client connected, hold an instance of protocoll. This is to be used to communicate with the client
    m_pProto = new cProtocolNet(pVal);
    m_pSock = pVal;
    m_bActive = TRUE;
    m_pThreadListe = pListen;
    // same discussion for protocoll is valid also for message pool
    // initialize messagge pool
    m_pMsgPool = new cPoolMsg;
    m_pMsgPool->Init();
    m_pProto->SetMsgPool(m_pMsgPool);  

}


////////////////////////////////////////
//       ~cConnClient
/*! 
*/

cConnClient::~cConnClient()
{
    if (m_pThreadListe)
    {
        m_pThreadListe->StopThread();
        SDL_Delay(100);
    }
    delete m_pProto;
    delete m_pThreadListe;
    delete m_pMsgPool;

}


