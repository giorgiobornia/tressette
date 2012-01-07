// cConnClient.h: interface for the cConnClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_cConnClient_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_)
#define AFX_cConnClient_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "SDL_net.h"

class cProtocolNet;
class Socket;
class cListenDataClient;
class cPoolMsg;


//! class cConnClient  
class cConnClient  
{
public:
	cConnClient(Socket* pVal, cListenDataClient* pListen);
    virtual ~cConnClient();
   

public:
    //! set player id
    void  SetId(ULONG ulVal){m_ulClientID = ulVal;}
    //! provides player id
    ULONG GetPlayerId(){return m_ulClientID;}
    
public:
    //! active flag
    BOOL           m_bActive;
    //! client sock
	Socket*        m_pSock;
    //! protocoll network
    cProtocolNet*  m_pProto;
    //! listening thread
    cListenDataClient*  m_pThreadListe;
    //! message pool
    cPoolMsg*       m_pMsgPool;

private:
    //! client  id
    ULONG            m_ulClientID;

};

#endif // !defined(AFX_cConnClient_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_)
