//I_BinderMsg.h

#ifndef _IBINDER_MSG_H_INTERFACE
#define _IBINDER_MSG_H_INTERFACE

class cMsgBase;
class cConnClient;

//! interface I_BinderMsg
class I_BinderMsg
{
public:
    //! client is disconnected
    virtual  void  ClientDisconnected(ULONG ulID) = 0;
    //! add message from player
    virtual  void  AddMsg(cMsgBase* pMsgBase, cConnClient* pConnClient) = 0;
};



#endif

