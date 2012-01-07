// cMsgCMD.h: interface for the cMsgCMD class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMSGCONNECTSERVER_H__641F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_)
#define AFX_CMSGCONNECTSERVER_H__641F6C6C_C82C_43B8_BA8A_A995C6A33AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cMsgBase.h"

//! class cMsgCMD
/** This message is used from server to send a command.
// This is a general message for command. In param1 there is the id of the command, 
// param2, param3, param4 are other parameters
*/
class cMsgCMD  : public  cMsgBase
{
    enum
    {
        NUMOFSTRINGS = 1,
        MAX_MSG_LEN = 1024,
        MAX_STRING_LEN = 230,
        LEN_PARAM1 = 1,
        LEN_PARAM2 = 1,
        LEN_PARAM3 = 1,
        LEN_PARAM4 = 1
    };
public:
	cMsgCMD();
	virtual ~cMsgCMD();

    //! build message for send CONNECT_SERVER
    BOOL    PrepareSend(LPCSTR lpsText, BYTE byParam1 = 0, BYTE byParam2 = 0, BYTE byParam3 = 0, BYTE byParam4 = 0);
    BOOL    PrepareSend(BYTE byParam1, BYTE byParam2);
    //! build message from  received buffer 
    virtual BOOL BuildOnRec(BYTE* pBuff, int iBuffLen);
    //! provides message text
    STRING  GetText(){return m_strText;}
    //! provides param 1
    BYTE    GetParam1(){return m_byParam1;}
    //! provides param 2
    BYTE    GetParam2(){return m_byParam2;}
    //! provides param 3
    BYTE    GetParam3(){return m_byParam3;}
    //! provides param 4
    BYTE    GetParam4(){return m_byParam4;}

private:
    //! text 
    STRING        m_strText;
    //! param 1 
    BYTE          m_byParam1;
     //! param 2 
    BYTE          m_byParam2;
     //! param 3 
    BYTE          m_byParam3;
     //! param 4 
    BYTE          m_byParam4;
    //! raw buffer (other view of text field)
    BYTE          m_DetDataField[MAX_STRING_LEN];
};

#endif 
