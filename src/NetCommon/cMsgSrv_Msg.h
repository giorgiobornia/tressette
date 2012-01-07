// cMsgSrv_Msg.h: interface for the cMsgSrv_Msg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMSGCONNECTSERVER_H__541F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_)
#define AFX_CMSGCONNECTSERVER_H__541F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cMsgBase.h"

//! class cMsgSrv_Msg
/** This message is used from server to send a text to the client.
// Text use also an id in param1 to identify informations, errors, ok....
*/
class cMsgSrv_Msg  : public  cMsgBase
{
    enum
    {
        NUMOFSTRINGS = 1,
        MAX_MSG_LEN = 1024,
        MAX_STRING_LEN = 230,
        LEN_PARAM1 = 1,
        LEN_PARAM2 = 1
    };
public:
	cMsgSrv_Msg();
	virtual ~cMsgSrv_Msg();

    //! build message for send CONNECT_SERVER
    BOOL    PrepareSend(LPCSTR lpsText, BYTE byParam1, BYTE byParam2);
    //! build message from  received buffer 
    virtual BOOL BuildOnRec(BYTE* pBuff, int iBuffLen);
    //! provides message text
    STRING  GetText(){return m_strText;}
    //! provides param 1
    BYTE    GetParam1(){return m_byParam1;}
    //! provides param 2
    BYTE    GetParam2(){return m_byParam2;}

private:
    //! text 
    STRING        m_strText;
    //! param 1 (ID of the text)
    BYTE          m_byParam1;
    //! param 2  (e.g.transId)
    BYTE          m_byParam2;
};

#endif 
