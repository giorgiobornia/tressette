// cMsgBase.h: interface for the cMsgBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMSGBASE_H__6147DC89_7E62_488E_9326_84EA756EBD77__INCLUDED_)
#define AFX_CMSGBASE_H__6147DC89_7E62_488E_9326_84EA756EBD77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "win_type_global.h"

/*
Steps to do when a new message is add:
    1) New class derived from cMsgBase
    2) add the new message type in eMsgType just before NUM_OF_MSG
    3) add pool in cPoolMsg (function Init(), addNewMsgInSlot() ), header: vector definition and new member
*/

//! class cMsgBase  
class cMsgBase  
{
    enum
    {
        MAX_SENT_BUFFER = 2048
    };

public:
    //! enum message type
    enum eMsgType
    {
        CMD = 0,
        SRV_MSG,
        CONNECT_SERVER,
        //Please don't insert a new type below
        NUM_OF_MSG,
        UNDEF
    };

public:
	cMsgBase();
	virtual ~cMsgBase();
    //! provides id low
    BYTE    GetIDLow(){return m_iMsgID_l;}
    //! provides id hight
    BYTE    GetIDHigh(){return m_iMsgID_h;}
    //! provides detail len
    BYTE    GetDetLen(){return m_iMsgDetailLen;}
    //! provides the message buffer
    BYTE*   GetBuf(){return m_byMsgDetail;}
    //! provides the type
    eMsgType  GetType(){return m_eType;}

    //! check the message type
    BOOL CheckType(int iID_Low, int iID_Hight);   
    //! build the message on recieved buffer
    virtual BOOL BuildOnRec(BYTE* pBuff, int iBuffLen) = 0;

// reference counting interface
    //! add ref
    void  AddRef(){InterlockedIncrement(&m_nRef);}
    //! release
    void  Release(){InterlockedDecrement(&m_nRef);}
    //! refence count
    int   RefCnt(){return m_nRef;}

public:
    //! message id low
    int   m_iMsgID_l;
    //! message id hight
    int   m_iMsgID_h;
    //! message ready
    BOOL  m_bMsgReady;
    //! message detail len sent
    int           m_iMsgDetailLen;
    //! message to be sent
    BYTE          m_byMsgDetail[MAX_SENT_BUFFER];
    //! reference count
    long          m_nRef;
    //! type
    eMsgType      m_eType;
};


#endif // !defined(AFX_CMSGBASE_H__6147DC89_7E62_488E_9326_84EA756EBD77__INCLUDED_)
