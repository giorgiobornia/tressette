// MsgQueueServer.h

#ifndef _MSGQUEUE_SERVER__H_
#define _MSGQUEUE_SERVER__H_

#include <sdl.h>
#include "SDL_net.h"
#include "SDL_thread.h"
#include "Socket.h"
#include "cConnClient.h"
#include <deque>
#include "cMsgBase.h"

//! class cQueueMSG
class cQueueMSG
{
public:
    cQueueMSG(){pClient = 0;  pMsgBase = 0;m_bValid = TRUE;}
    cQueueMSG(cConnClient* pVal, cMsgBase* pVal2){pClient = pVal; pMsgBase = pVal2;m_bValid = TRUE;}
    
    //! copy operator
    void operator = (const cQueueMSG& msg);
    //! provides valid value
    BOOL GetIsValid(){return m_bValid;}
    //! set valid
    void SetValid(BOOL bVal){m_bValid = bVal;}
    //! netplayer pointer
    cConnClient*           pClient;
    //! message type
    cMsgBase*              pMsgBase;

private:
    //! valid flag
    BOOL                   m_bValid;
};

typedef std::deque<cQueueMSG> DEQ_QUEUEMSG; 

//! class cQueueMsgServer
class cQueueMsgServer
{
public:
    cQueueMsgServer(){pMxAccMsg = 0; pCond = 0;m_bSynchCreated = FALSE;}
    ~cQueueMsgServer();

    //! initialize  stuff
    void    Init();

// event functions
    //! put message (raise signal)
    void    PutMsg(cQueueMSG &Msg);
    //! get message (blocking)
    BOOL    GetMsg(cQueueMSG* pMsg);
    //! reset the queue
    void Reset();
    
// polling functions
    //! get message in the queue if it is present
    BOOL    GetMsgNoSig(cQueueMSG* pMsg);
    //! put message in the queue no signal
    void    PutMsgNoSig(cQueueMSG &Msg);

    //! mutex access message   queue
    SDL_mutex*     pMxAccMsg;
    //! condition queue
    SDL_cond*      pCond;
    //! queue messages to process in main thread
    DEQ_QUEUEMSG   deqMsg;

private:
    //! flag for synch creation stuff
    BOOL    m_bSynchCreated;
};


#endif