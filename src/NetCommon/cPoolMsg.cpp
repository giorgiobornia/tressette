// cPoolMsg.cpp: implementation of the cPoolMsg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cPoolMsg.h"

#include "cMsgConnectServer.h"
#include "cMsgSrv_Msg.h"
#include "cMsgCMD.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cPoolMsg::cPoolMsg()
{

}


////////////////////////////////////////
//       ~cPoolMsg
/*! 
*/
cPoolMsg::~cPoolMsg()
{
    for (int iSlot = 0; iSlot < cMsgBase::NUM_OF_MSG; iSlot++)
    {
        // go throw all message types
        for (int i = 0; i < m_vctvctMsgBase[iSlot].size(); i++)
        {
            delete m_vctvctMsgBase[iSlot][i];
        }
        
    }
}


////////////////////////////////////////
//       Init
/*! Initialize the memory (alloc messages) 
*/
void  cPoolMsg::Init()
{
    for (int iSlot = 0; iSlot < cMsgBase::NUM_OF_MSG; iSlot++)
    {
        // go throw all message types

        if (iSlot == cMsgBase::CMD)
        {
            VCT_PMSG vct_pBaseMsg;
            for (int i = 0; i < NUM_INIT_ELEM; i++)
            {
                cMsgConnectServer* pTmpMsg = new cMsgConnectServer;
                m_vctpMsgConnServ.push_back(pTmpMsg);
                vct_pBaseMsg.push_back(pTmpMsg);
            }
            m_vctvctMsgBase.push_back(vct_pBaseMsg);
        }
        else if (iSlot == cMsgBase::SRV_MSG)
        {
            VCT_PMSG vct_pBaseMsg;
            for (int i = 0; i < NUM_INIT_ELEM; i++)
            {
                cMsgSrv_Msg* pTmpMsg = new cMsgSrv_Msg;
                m_vctpMsgSrvMsg.push_back(pTmpMsg);
                vct_pBaseMsg.push_back(pTmpMsg);
            }
            m_vctvctMsgBase.push_back(vct_pBaseMsg);
        }
        else if (iSlot == cMsgBase::CONNECT_SERVER)
        {
            VCT_PMSG vct_pBaseMsg;
            for (int i = 0; i < NUM_INIT_ELEM; i++)
            {
                cMsgCMD* pTmpMsg = new cMsgCMD;
                m_vctpMsgCMD.push_back(pTmpMsg);
                vct_pBaseMsg.push_back(pTmpMsg);
            }
            m_vctvctMsgBase.push_back(vct_pBaseMsg);
        }

    }
}


////////////////////////////////////////
//       GetPoolMsg
/*! Provides the next usable message in the pool
// \param int iSlot : slot number
// \param cMsgBase** ppMsg : returned message pointer
*/
void  cPoolMsg::GetPoolMsg(int iSlot, cMsgBase** ppMsg)
{
    ASSERT(ppMsg);
    ASSERT(iSlot >= 0 && iSlot < m_vctvctMsgBase.size());
    *ppMsg = findNextAvail_Msg(iSlot, m_vctvctMsgBase[iSlot]);
}


////////////////////////////////////////
//       findNextAvail_Msg
/*! Provides the next available message in the slot
// \param VCT_PMSG& vct_pMsg : slot
*/
cMsgBase*  cPoolMsg::findNextAvail_Msg(int iSlot, VCT_PMSG& vct_pMsg)
{
    cMsgBase* pRetVal = 0;
    BOOL bAvail = FALSE;

    int iNumElem = vct_pMsg.size();
    ASSERT(iNumElem < 2000);

    for (int i = 0; i < iNumElem; i++)
    {
        pRetVal = vct_pMsg[i];
        if (pRetVal->RefCnt() <= 0)
        {
            // ok message available
            bAvail = TRUE;
            break;
        }
    }

    if (!bAvail)
    {
        // we need to add new messages in the slot
        pRetVal = addNewMsgInSlot(iSlot);
    }
    

    return pRetVal;
}


////////////////////////////////////////
//       addNewMsgInSlot
/*! Add new elements in the slot. Return the first new inserted element
// \param int iSlot : slot number
*/
cMsgBase*  cPoolMsg::addNewMsgInSlot(int iSlot)
{
    cMsgBase* pRetVal = 0;

    if (iSlot == cMsgBase::CMD)
    {
        for (int i = 0; i < NUM_INIT_ELEM; i++)
        {
            cMsgConnectServer* pTmpMsg = new cMsgConnectServer;
            m_vctpMsgConnServ.push_back(pTmpMsg);
            m_vctvctMsgBase[iSlot].push_back(pTmpMsg);
            if (i == 0)
            {
                pRetVal = pTmpMsg;
            }
        }
        
    }
    else if (iSlot == cMsgBase::SRV_MSG)
    {
        for (int i = 0; i < NUM_INIT_ELEM; i++)
        {
            cMsgSrv_Msg* pTmpMsg = new cMsgSrv_Msg;
            m_vctpMsgSrvMsg.push_back(pTmpMsg);
            m_vctvctMsgBase[iSlot].push_back(pTmpMsg);
            if (i == 0)
            {
                pRetVal = pTmpMsg;
            }
        }
        
    }
    else if (iSlot == cMsgBase::CONNECT_SERVER)
    {
        for (int i = 0; i < NUM_INIT_ELEM; i++)
        {
            cMsgCMD* pTmpMsg = new cMsgCMD;
            m_vctpMsgCMD.push_back(pTmpMsg);
            m_vctvctMsgBase[iSlot].push_back(pTmpMsg);
            if (i == 0)
            {
                pRetVal = pTmpMsg;
            }
        }
        
    }

    return pRetVal;
}


////////////////////////////////////////
//       Collect
/*! Collect garbage
*/
void  cPoolMsg::Collect()
{
    ASSERT(0);
}


