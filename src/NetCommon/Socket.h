// Socket.h

#ifndef _SOCKET_H__
#define _SOCKET_H__

#include "win_type_global.h"

#include "SDL_net.h"
#include "SDL_thread.h"
#include <string>

//! function pointer for thread proxy casting
typedef int (*LP_FNTHREAD)(void*);

//! class Socket
class Socket
{
public:
	//! Constructor
	Socket(TCPsocket socket);
	//! Constructor
    Socket();
    //! destructor
	virtual ~Socket();

public:
    //! Init
    int Init(const std::string& host, int port);
	//! Connect
	virtual BOOL  Connect(bool use_thread = false, bool reconnect = false);
	//! disconnect
	virtual void Disconnect();
	//! provides the name of the host
    const char* GetHostname(){return m_strHost.c_str();}
	//! Provides port number
	int GetPort();
	//! true if the socket is connected
	bool IsOnline(){return m_bOnline;}
    //! wait a fix ms to receive data
	bool WaitForData(int ms_timeout);
    //! send data
	int Send(void* data, int len);
    //! receive some data
	int Receive(void* data, int len);
	//! accept client socket
	Socket* Accept();
    //! open a new socket
    BOOL     Open();
    //! provides the tcp sdl socket
    TCPsocket GetTCPSocket(){return m_Sock;}



private:
    //! flag online socket connected
	bool          m_bOnline;
	//! host name
	std::string   m_strHost;
	//! port number
	int           m_iPort;
	//! ip address information
	IPaddress*    m_pIPadd;
    //! curent sdl socket
	TCPsocket     m_Sock;
	//! socket set
	SDLNet_SocketSet  m_SocketSet;
};

#endif
