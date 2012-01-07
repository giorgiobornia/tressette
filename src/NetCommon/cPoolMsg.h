// cPoolMsg.h: interface for the cPoolMsg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPOOLMSG_H__5EED5992_6ABE_4D42_A694_62D3D509213B__INCLUDED_)
#define AFX_CPOOLMSG_H__5EED5992_6ABE_4D42_A694_62D3D509213B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cMsgBase.h"
#include <vector>

class cMsgConnectServer;
class cMsgSrv_Msg;
class cMsgCMD;

typedef std::vector<cMsgBase*>  VCT_PMSG;
typedef std::vector<VCT_PMSG>   VCT_VCT_PMSG;
typedef std::vector<cMsgConnectServer*> VCT_PMSG_CONNECTSERVER;
typedef std::vector<cMsgSrv_Msg*> VCT_PMSG_SERVERTEXT;
typedef std::vector<cMsgCMD*> VCT_PMSG_CMD;

//! class cPoolMsg  
class cPoolMsg  
{
    enum
    {
        NUM_INIT_ELEM = 10
    };
public:
	cPoolMsg();
	virtual ~cPoolMsg();

    //! init
    void  Init();
    //! get message slot
    void  GetPoolMsg(int iSlot, cMsgBase** ppMsg);
    //! collect the garbage
    void  Collect();

private:
    cMsgBase*  findNextAvail_Msg(int iSlot, VCT_PMSG& vct_pMsg);
    cMsgBase*  addNewMsgInSlot(int iSlot);

private:
    //! connect server pool
    VCT_PMSG_CONNECTSERVER  m_vctpMsgConnServ;
    //! matrix of  base messages
    VCT_VCT_PMSG            m_vctvctMsgBase;
    //! msg text server
    VCT_PMSG_SERVERTEXT     m_vctpMsgSrvMsg;
    //! msg commands
    VCT_PMSG_CMD            m_vctpMsgCMD;

};

#endif // !defined(AFX_CPOOLMSG_H__5EED5992_6ABE_4D42_A694_62D3D509213B__INCLUDED_)
