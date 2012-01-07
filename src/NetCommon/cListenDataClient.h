// cListenDataClient.h: interface for the cListenDataClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLISTENDATACLIENT_H__873E36F7_1E5C_445C_9ACD_493297720464__INCLUDED_)
#define AFX_CLISTENDATACLIENT_H__873E36F7_1E5C_445C_9ACD_493297720464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "I_BinderMsg.h"
#include "SDL_thread.h"

//class cNetServer;
class Socket;

//! class cListenDataClient  
class cListenDataClient  
{
    enum
    {
        BUFFLEN = 1048
    };
public:
	cListenDataClient(I_BinderMsg* pVal,  Socket*pS);
    

    virtual ~cListenDataClient();

public:
    //! run listene thread
    void Run();
    //! set connected client
    void SetConnClient(cConnClient* pVal){m_pConnClient = pVal;}
    //! stop the thread
    void StopThread();
   
private:
    static int stath_ListenClient(cListenDataClient* pThis)
        {return pThis->th_ListenClient();}
    
    //! Wait data from client
    int th_ListenClient();
    

    //! Analysis of recived message stack
    void handleMessage();
    

private:
    //! client socket
    Socket*      m_pSock;
    //! server object pointer
    I_BinderMsg* m_pBinder;
    //! net  client reference
    cConnClient* m_pConnClient;
    //! terminator flag
    BOOL         m_bTerminated;
    //! listening thread handler
    SDL_Thread*  m_hThListen;
    
};

#endif // !defined(AFX_CLISTENDATACLIENT_H__873E36F7_1E5C_445C_9ACD_493297720464__INCLUDED_)
