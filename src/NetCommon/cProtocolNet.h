// cProtocolNet.h: interface for the cProtocolNet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPROTOCOLNET_H__028C674A_C115_4B99_BCC2_500FEFD9D0C9__INCLUDED_)
#define AFX_CPROTOCOLNET_H__028C674A_C115_4B99_BCC2_500FEFD9D0C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "win_type_global.h"

#include "InvidoInfoComm.h"
#include <string>
#include "cMsgBase.h"

class Socket;
class cPoolMsg;

#ifndef STRING
    typedef std::string STRING;
#endif



//! class cProtocolNet  
/** Client and server share information sending messages. A message is a sequence of bytes.
//  The structure of a message is follow:

 1       2      3        ....<message specific>.....    
----------------------------------------------------------------------------------
| ID0 | ID1| SUB ID0 | SUB ID1| DETLEN0 | DETLEN1 |  ...data.... | CRC1   | CRC2 |
----------------------------------------------------------------------------------
*/
class cProtocolNet  
{
public:
    enum
    {
        MAX_BUFFER_RECEIVED = 2*2048,
        MAX_BUFFER_BROKEN = 1024,
        ID_LEN = 2,
        CRC_LEN = 2,
        PROTOCOL_VERSION = 1,
        LEN_LEN = 2,
        MIN_MSG_LEN = 5,
        SUB_ID_LEN = 2,
        MAX_LEN_DET = 256,
        MSG_PCK_LEN = ID_LEN + SUB_ID_LEN + LEN_LEN + CRC_LEN
    };

    typedef std::deque<cMsgBase*> DEQ_PMSG;
    //! public enum used to identify server message parameters and commands
    /** use this convention: <name message>_<param order>_<identifier>
    */
    enum
    {
        MAX_MSG_LEN = 1024,
        SRVMSG_1_OK = 0,
        SRVMSG_1_INFO = 1,
        SRVMSG_1_ERROR = 2,
        CMDMSG_LOGOUT   = 1,
        CMDMSG_CONNUSER = 2,
        CMDMSG_DISCONNUSER = 3,
        CMDMSG_GETNUMCONNECTED = 4,
        CMDMSG_NUMOFCONNECTED = 5,
        CMDMSG_CREATETABLE = 6,
        CMDMSG_JOINTABLE = 7,
        CMDMSG_SITONTABLE =  8,
        CMDMSG_NEWMATCHREQ = 9,
        CMDMSG_NEWMATCH_CFM = 10,
        PARAM_NOTUSED = 0xff
    };

public:
	cProtocolNet(Socket* pSock);
	virtual ~cProtocolNet();

    //! parse a byte array message
    BOOL  ParseRawMessage(BYTE* pByteArrRes, int iLen);
    //! get received message type
    BOOL  GetNextMsg(cMsgBase** ppMsg);
  
    //! send message
    BOOL  Send(cMsgBase& oMsg);
    //! set message pool
    void  SetMsgPool(cPoolMsg* pVal){m_pMsgPool = pVal;}

private:
    BOOL  checkBrokenMsg(int iIndex, int iBuffTotLen);
    void  updateAvailMsg(cMsgBase** m_apAllMsgAvail);


private:
    //! message to be sent
    BYTE          m_bySentMessage[MAX_BUFFER_RECEIVED];
    //! message total len sent 
    int           m_iMsgSentTotalLen;
    //! message detail len sent
    int           m_iMsgSentDetailLen;
    //! message received
    BYTE          m_byRecMessage[MAX_BUFFER_RECEIVED];
    //! message total len sent 
    int           m_iMsgRecTotalLen;
    //! message detail len received
    int           m_iMsgRecDetailLen;
    //! message broken in buffer
    BYTE          m_byBrokenMessage[MAX_BUFFER_BROKEN];
    //! crc 1
    BYTE          m_byCrc1;
    //! crc 1
    BYTE          m_byCrc2;
    //! protocol version
    int           m_iVersion;
    //! socket pointer
    Socket*       m_pSocket;
    //! messages received
    DEQ_PMSG      m_deqpRecMsg;
    //! len of broken message
    int           m_iLenBrokenMsg;
    //! messages available in protocoll
    cMsgBase*     m_apAllMsgAvail[cMsgBase::NUM_OF_MSG];
    //! message pool
    cPoolMsg*     m_pMsgPool;
};

#endif // !defined(AFX_CPROTOCOLNET_H__028C674A_C115_4B99_BCC2_500FEFD9D0C9__INCLUDED_)
