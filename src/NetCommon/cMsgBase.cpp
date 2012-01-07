// cMsgBase.cpp: implementation of the cMsgBase class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#ifdef USEDIALOGTRACE
    #include "testengine.h"
#endif
#include "cMsgBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cMsgBase::cMsgBase()
{
    m_iMsgID_l = -1;
    m_iMsgID_h = -1;
    m_bMsgReady = FALSE;
    m_iMsgDetailLen = 0;
    m_nRef = 0;
}

cMsgBase::~cMsgBase()
{

}


////////////////////////////////////////
//       CheckType
/*! Check the type of the message
// \param int iID_Low : 
// \param int iID_Hight : 
*/
BOOL cMsgBase::CheckType(int iID_Low, int iID_Hight)
{
    BOOL bRes = FALSE;
    if (m_iMsgID_l == iID_Low &&
        iID_Hight == m_iMsgID_h)
    {
        bRes = TRUE;
    }
    return bRes;
}

