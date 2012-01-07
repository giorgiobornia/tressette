// cTransaction.h: interface for the cTransaction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTRANSACTION_H__D11E1F6E_3ABB_40F4_9A1E_70EED0868F74__INCLUDED_)
#define AFX_CTRANSACTION_H__D11E1F6E_3ABB_40F4_9A1E_70EED0868F74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <functional>
#include <list>

//! class cTrasDet
class cTrasDet
{
public:
    enum eType
    {
        NOTDEF = 0,
        //! login transaction
        LOGIN,
        //! logout transaction
        LOGOUT,
        //! command transactions
        CMD
    };
	
    cTrasDet(){m_eTranType = NOTDEF; m_uiIDTrans = 0; m_uiTickStart= 0;}
    cTrasDet(eType eVal, UINT uiVal, UINT uiTick){m_eTranType = eVal; m_uiIDTrans = uiVal;m_uiTickStart = uiTick;}

    //! trans type
    eType m_eTranType;
    //! id trans
    UINT  m_uiIDTrans;
    //! tick on start
    UINT  m_uiTickStart;

};

//! operator for trace transaction
inline std::ostream &operator << (std::ostream &stream, const cTrasDet &o)
{
    stream << "Trans type: " << o.m_eTranType << std::endl;
    stream << "Trans id: " << o.m_uiIDTrans << std::endl;
    stream << "Trans tick start: " << o.m_uiTickStart << std::endl;
    return stream;
}

typedef std::list<cTrasDet> DEQ_TRANSDET; 
typedef DEQ_TRANSDET::iterator  IT_DEQ_TRANS;

//! class cmpTransID_eq
/** Predicate to  Find a transaction in the queue
*/
class cmpTransID_eq : public std::unary_function<cmpTransID_eq, bool>
{
private:
    UINT m_uiValRef;

public:
    // constructor
    explicit cmpTransID_eq(const UINT uiVal): m_uiValRef(uiVal){}
    //operator ()
    bool operator ()(cTrasDet& Element)
    {
        
        return Element.m_uiIDTrans == m_uiValRef;
    }
};

//! class cTransaction  
class cTransaction  
{
public:
    cTransaction();
	virtual ~cTransaction();

    //! insert and start a new transaction
    UINT Insert(cTrasDet::eType eVal);
    //! find a transaction
    BOOL FindTrans(UINT uiTransId, cTrasDet* pTrasRes);
    //! remove transaction from the list
    BOOL RemoveTrans(UINT uiTransId);

    friend std::ostream &operator << (std::ostream &stream, const  cTrasDet &o);

private:
    //! transaction queue
    DEQ_TRANSDET     m_lstTransDet;
    //! transaction id
    UINT             m_uiTransId;
};

#endif // !defined(AFX_CTRANSACTION_H__D11E1F6E_3ABB_40F4_9A1E_70EED0868F74__INCLUDED_)
