// cListenData.h: interface for the cListenData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLISTENDATA_H__87D4ABEA_3636_4A48_9802_D77DB18C21B2__INCLUDED_)
#define AFX_CLISTENDATA_H__87D4ABEA_3636_4A48_9802_D77DB18C21B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct SDL_Thread;
class Socket;
class cNetClient;
class cProtocolNet;
class cNetPlayer;

//! class cListenData  
class cListenData  
{
    enum
    {
        BUFFLEN = 1024
    };

public:
    enum eType
    {
        SERVER,
        PEER
    };
public:
	cListenData(cNetClient* pVal,  Socket*pS, eType eVal, cNetPlayer* pNet);
	virtual ~cListenData();
    //! start listening
    void  Run();
    //! stop the thread
    void StopThread();
    //! set protocoll
    void SetProtoColl(cProtocolNet* pVal){m_pProto = pVal;}

private:
    static int stath_ListenForData(cListenData* pThis)
        {return pThis->th_ListenForData();}
    
    int th_ListenForData();

private:
    //! pear/server socket
    Socket*      m_pSock;
    //! client object pointer
    cNetClient*  m_pNetClient;
    //! net protocoll
    cProtocolNet*  m_pProto;
    //! terminator flag
    BOOL         m_bTerminated;
    //! connection type
    eType        m_eTypeConn;
    //! server listener thread handler
    SDL_Thread*  m_hThServerList;
    //! peer listener thread handler
    SDL_Thread*  m_hThPeerList;
    //! object that identify the peer (peer or server)
    cNetPlayer*  m_pNetPlayer;
};

#endif // !defined(AFX_CLISTENDATA_H__87D4ABEA_3636_4A48_9802_D77DB18C21B2__INCLUDED_)
