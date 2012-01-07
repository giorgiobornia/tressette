// MsgQueueServer.cpp

#include "win_type_global.h"
#include "MsgQueueServer.h"

//////////////////////////////////////////////////////////////////////
// cQueueMSG
//////////////////////////////////////////////////////////////////////


////////////////////////////////////////
//       operator = 
/*! Copy a message
// \param const cQueueMSG& msg : 
*/
void cQueueMSG::operator = (const cQueueMSG& msg)
{
    pClient = msg.pClient ;
    pMsgBase = msg.pMsgBase; 
    m_bValid = msg.m_bValid;
    
}


//////////////////////////////////////////////////////////////////////
// cQueueMsgServer
//////////////////////////////////////////////////////////////////////
cQueueMsgServer::~cQueueMsgServer()
{
    SDL_DestroyMutex(pMxAccMsg);
    SDL_DestroyCond(pCond);

}

////////////////////////////////////////
//       Init
/*! Initialize queue
*/
void cQueueMsgServer::Init()
{
    if (!m_bSynchCreated)
    {
        pMxAccMsg = SDL_CreateMutex();
        pCond = SDL_CreateCond();
        m_bSynchCreated = TRUE;
    }
    deqMsg.clear();
}



////////////////////////////////////////
//       PutMsg
/*! Put message and trigger the signal for get message
// \param cQueueMSG &Msg : 
*/
void cQueueMsgServer::PutMsg(cQueueMSG &Msg)
{
    // lock mutex 
    SDL_LockMutex(pMxAccMsg);
        
        deqMsg.push_back(Msg);   
        SDL_CondSignal(pCond);
    // unlock mutex 
    SDL_UnlockMutex(pMxAccMsg);
}

////////////////////////////////////////
//       GetMsg
/*! Provides the message 
// \param cQueueMSG* pMsg : pointer to the returned message.
*/
BOOL  cQueueMsgServer::GetMsg(cQueueMSG* pMsg)
{
    BOOL bRet = FALSE;
    ASSERT(pMsg);
    // get a message from queue
    // lock mutex 
    SDL_LockMutex(pMxAccMsg);
    //SDL_mutexP(m_pMxAccMsgServ);
        while(1)
        {
            int iNumMsg = deqMsg.size();
            if (iNumMsg > 0)
            {
                *pMsg =  deqMsg.front();   
                deqMsg.pop_front();
                // message received, exit
                bRet = TRUE;
                break;
            }
            else
            {
                // no messages, wait signal
                SDL_CondWait( pCond,  pMxAccMsg);
            }
        }
    // unlock mutex 
    SDL_UnlockMutex( pMxAccMsg);
    return bRet;
}


////////////////////////////////////////
//       PutMsgNoSig
/*! Same as PutMsg, but with no signal
// \param cQueueMSG &Msg : 
*/
void cQueueMsgServer::PutMsgNoSig(cQueueMSG &Msg)
{
    // lock mutex 
    SDL_LockMutex(pMxAccMsg);
        deqMsg.push_back(Msg);   
    // unlock mutex 
    SDL_UnlockMutex(pMxAccMsg);
}


////////////////////////////////////////
//       GetMsgNoSig
/*! Provides the message in the queue with no blocking of put signal
// \param cQueueMSG* pMsg : 
*/
BOOL  cQueueMsgServer::GetMsgNoSig(cQueueMSG* pMsg)
{
    BOOL bRet = FALSE;
    ASSERT(pMsg);
    pMsg->SetValid(FALSE) ;
    // get a message from queue
    // lock mutex 
    SDL_LockMutex(pMxAccMsg);
        int iNumMsg = deqMsg.size();
        if (iNumMsg > 0)
        {
            *pMsg =  deqMsg.front();   
            deqMsg.pop_front();
            // message received, exit
            bRet = TRUE;
            pMsg->SetValid(TRUE) ;
        }
        else
        {
            // no messages
        }
    // unlock mutex 
    SDL_UnlockMutex( pMxAccMsg);
    return bRet;
}


////////////////////////////////////////
//       Reset
/*! Clear the queue
*/
void cQueueMsgServer::Reset()
{
    SDL_LockMutex(pMxAccMsg);
        deqMsg.clear();
    SDL_UnlockMutex( pMxAccMsg);
}
