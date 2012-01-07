// cTransaction.cpp: implementation of the cTransaction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "win_type_global.h"
#include "cTransaction.h"
#include <SDL.h>
#include <algorithm>

#include "tracestl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cTransaction::cTransaction()
{
    m_uiTransId = 0;
}

cTransaction::~cTransaction()
{

}



////////////////////////////////////////
//       Insert
/*! Start a new transaction and insert it in the queue
// \param cTrasDet::eType eVal : type of transaction
*/
UINT cTransaction::Insert(cTrasDet::eType eVal)
{
    m_uiTransId++;
    m_lstTransDet.push_back(cTrasDet(eVal, m_uiTransId, SDL_GetTicks() ));

    return m_uiTransId;
}


////////////////////////////////////////
//       FindTrans
/*! Find a transaction in the queue
// \param int iTransId : transaction id
// \param cTrasDet* pTrasRes : transaction result
*/
BOOL cTransaction::FindTrans(UINT uiTransId, cTrasDet* pTrasRes)
{
    BOOL bRes = FALSE;
    ASSERT(pTrasRes);

    IT_DEQ_TRANS it_result;
    it_result = std::find_if(m_lstTransDet.begin(), m_lstTransDet.end(), 
            cmpTransID_eq(uiTransId));

    if (it_result != m_lstTransDet.end())
    {
        // item found
        *pTrasRes = *it_result;
        bRes = TRUE;
    }

    pTrasRes = NULL;
    return bRes;
}


////////////////////////////////////////
//       RemoveTrans
/*! REmove a transaction from the list
// \param UINT uiTransId : id of transaction to be removed
*/
BOOL cTransaction::RemoveTrans(UINT uiTransId)
{
    BOOL bRes = FALSE;

    //TraceContainer(m_lstTransDet, "Before remove");

    IT_DEQ_TRANS it_result = std::find_if(m_lstTransDet.begin(), m_lstTransDet.end(), 
            cmpTransID_eq(uiTransId));

    if (it_result != m_lstTransDet.end())
    {
        m_lstTransDet.erase( it_result );
        bRes = TRUE;
    }

    //TraceContainer(m_lstTransDet, "After remove");
    
    return bRes;
}


