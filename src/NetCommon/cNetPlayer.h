// cNetPlayer.h: interface for the cNetPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CNETPLAYER_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_)
#define AFX_CNETPLAYER_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "SDL_net.h"

class cProtocolNet;
class Socket;
class cListenDataClient;
class cPoolMsg;


//! class cNetPlayer  
class cNetPlayer  
{
public:
	cNetPlayer(Socket* pVal, cListenDataClient* pListen);
	virtual ~cNetPlayer();

public:
    //! set player id
    void  SetId(ULONG ulVal){m_ulPlayerID = ulVal;}
    //! provides player id
    ULONG GetPlayerId(){return m_ulPlayerID;}
    
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
    //! player id
    ULONG            m_ulPlayerID;

};

#endif // !defined(AFX_CNETPLAYER_H__43DBAF35_2177_40F7_B591_C535F8006275__INCLUDED_)
