// cListenData.cpp: implementation of the cListenData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "testengine.h"
#include "cListenData.h"

#include "cNetClient.h"
#include "Socket.h"
#include "cProtocolNet.h"
#include "cNetPlayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cListenData::cListenData(cNetClient* pVal,  Socket*pS, eType eVal, cNetPlayer* pNet)
{
    m_pSock = pS;
    m_pNetClient = pVal;
    m_bTerminated = FALSE;
    m_eTypeConn = eVal;
    m_hThServerList = 0;
    m_hThPeerList = 0;
    m_pNetPlayer = pNet;
}

cListenData::~cListenData()
{

}


////////////////////////////////////////
//       StopThread
/*! Sto the listen thread
*/
void cListenData::StopThread()
{
    m_bTerminated = TRUE;
    if (m_eTypeConn == SERVER)
    {
        SDL_WaitThread(m_hThServerList, NULL);
    }
    else if(m_eTypeConn == PEER)
    {
        SDL_WaitThread(m_hThPeerList, NULL);
    }
}


////////////////////////////////////////
//       Run
/*! Start listening data
*/
void cListenData::Run()
{
    SDL_Thread*  hHandle = SDL_CreateThread((LP_FNTHREAD)stath_ListenForData, this);
    if (m_eTypeConn == SERVER)
    {
        m_hThServerList = hHandle;
    }
    else if(m_eTypeConn == PEER)
    {
        m_hThPeerList = hHandle;
    }
}



////////////////////////////////////////
//       th_ListenForData
/*! Thread that listen data
*/
int cListenData::th_ListenForData()
{
    m_bTerminated = FALSE;

    BYTE byBuffer[BUFFLEN];
    while(!m_bTerminated)
    {
        if (m_pSock->WaitForData(1))
        {
            int iLen = m_pSock->Receive(byBuffer, BUFFLEN);
            // data are available
            if ( iLen  > 0 )
            {
                // data received ok
                m_pProto->ParseRawMessage(byBuffer, iLen);  
                cMsgBase* pMsgBase;
                while( m_pProto->GetNextMsg(&pMsgBase) )
                {
                    //m_pNetClient->ProcessMsg(pMsgBase, m_eTypeConn);
                    m_pNetClient->AddMsg(pMsgBase, m_pNetPlayer);
                }
            }
            else
            {
                // socket is disconnected
                m_pNetClient->SockDisconnected(m_eTypeConn);
                // disconnected
                // pay attention terminate condition: if m_pNetClient stop the
                // the thread and set m_bTerminated = TRUE, no callback notification are to be used
                m_bTerminated = TRUE;
            }
        }
    }
    

    return 0;
}


