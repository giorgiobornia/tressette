// Socket.cpp

#include "Socket.h"
#include "Log.h"


////////////////////////////////////////
//       Socket
/*! Costructor using an assigned TCPsocket
// \param TCPsocket socket : 
*/
Socket::Socket(TCPsocket socket)
{
	m_Sock = socket;
	m_bOnline = true;
	m_SocketSet = SDLNet_AllocSocketSet(1);
	SDLNet_TCP_AddSocket(m_SocketSet, m_Sock);
	
    // store information about socket
    m_pIPadd = SDLNet_TCP_GetPeerAddress(socket);

    CHAR buff[128];
    Uint32 ipaddr;
    m_iPort = m_pIPadd->port;
    ipaddr = SDL_SwapBE32(m_pIPadd->host);
    sprintf(buff, "%d.%d.%d.%d", ipaddr>>24, (ipaddr>>16)&0xff, (ipaddr>>8)&0xff, ipaddr&0xff);

    m_strHost = buff;
	
}

////////////////////////////////////////
//       Socket
/*! Default constructor
*/
Socket::Socket()
{

	m_bOnline = false;
	m_strHost = "";
	m_iPort = 0;
	m_Sock = NULL;
	m_SocketSet = SDLNet_AllocSocketSet(1);
	m_pIPadd = new IPaddress();
	
}


////////////////////////////////////////
//       ~Socket
/*! 
*/
Socket::~Socket() 
{
	
	Disconnect();
	if (m_pIPadd) 	
    {
        delete m_pIPadd;
    }

	SDLNet_FreeSocketSet(m_SocketSet);
}


////////////////////////////////////////
//       Init
/*! Initialize the socket
// \param const std::string& host :  host string. Null string is this computer. 
// \param int port : Port to be open.
*/
int Socket::Init(const std::string& host, int port)
{
    m_strHost = host;
    m_iPort = port;

	if (m_iPort < 1 || m_iPort > 65534) 
    {
		debug->Print(0, "Socket Error: Invalid port\n"); 
        return -1;
	}

	// host and port
	if (m_strHost == "") 
    {
		if (SDLNet_ResolveHost(m_pIPadd, NULL, m_iPort)) 
        {
			debug->Print(0, "Socket Error: Resolve host error\n"); 
            return -1;
		}
	} 
    else 
    {
		if (SDLNet_ResolveHost(m_pIPadd, (char*)m_strHost.c_str(), m_iPort)) 
        {
			debug->Print(0, "Socket Error: host not found\n"); 
            return -1;
		}
	}
    return 0;
}

////////////////////////////////////////
//       Connect
/*! Connect to the server socket
// \param bool use_thread : 
// \param bool reconnect : 
*/
BOOL  Socket::Connect(bool use_thread, bool reconnect) 
{
    BOOL bRes = TRUE;

	if (reconnect) 
    {

		if (m_bOnline) 
        {			
			Disconnect();
		} 
	}
	
	m_Sock = SDLNet_TCP_Open(m_pIPadd);
	if (m_Sock == NULL) 
    {
		debug->Print(0, "Socket Error: connection open error\n"); 
        return FALSE;
	}

	SDLNet_TCP_AddSocket(m_SocketSet, m_Sock);
	m_bOnline = true;

    return bRes;

}


////////////////////////////////////////
//       Disconnect
/*! Disconnect socket
*/
void Socket::Disconnect() 
{
	
	if (m_bOnline) 
    {
	    while (SDLNet_TCP_DelSocket(m_SocketSet, m_Sock) >= 0)
        {
		    SDLNet_TCP_Close(m_Sock);
        }
    }
	
	m_Sock = NULL;
	m_bOnline = false;
	
}


////////////////////////////////////////
//       WaitForData
/*! Wait a fix ms for data on the socket. Returns true if data are available.
// \param int ms_timeout : timeout
*/
bool Socket::WaitForData(int ms_timeout) 
{
	SDLNet_CheckSockets(m_SocketSet, ms_timeout);
    bool bVal = SDLNet_SocketReady(m_Sock) ? false : true;

	return (!bVal);
}


////////////////////////////////////////
//       Send
/*! Send data on the socket
// \param void* data : 
// \param int len : 
*/
int Socket::Send(void* data, int len) 
{
	if (!m_Sock || !m_bOnline)
        return -1;

	int result = 0;
	
	result = SDLNet_TCP_Send(m_Sock, data, len);

	debug->Print(3, "[Socket::Send] sock=%p data=%p len=%d result=%d\n", m_Sock, data, len, result);
	
    if (result <= 0) 
    {
		Disconnect();
		debug->Print(0, "Socket Error: Send error\n"); 
        
	}
	
    return result;
}


////////////////////////////////////////
//       Receive
/*! Receive data on the socket. Returns the number of bytes read
// \param void* data : pointer to result buffer
// \param int len : len of the buffer
// \param bool all : true if all data are read
*/
int Socket::Receive(void* data, int len) 
{
    if (!m_Sock || !m_bOnline)
        return -1;
	
		
	int iResult = SDLNet_TCP_Recv(m_Sock, data, len);

    if (iResult > 0 )
    {
	    debug->TraceData(3,  (const BYTE*)data, iResult, "[Socket::Receive]");
    }
	else 
    {
		Disconnect();
		debug->Print(3, "[Socket:Closed]\n");
	}

    return iResult;
}


////////////////////////////////////////
//       Accept
/*! Accept socket connection
*/
Socket* Socket::Accept() 
{
    Socket* pSock = 0;
    if (m_Sock)
    {
        
	    TCPsocket new_sock;
	    new_sock = SDLNet_TCP_Accept(m_Sock);
	    if (new_sock) 
        {
		    pSock =  new Socket(new_sock);
            m_bOnline = true;
        }
        
    }
    else
    {
        debug->Print(0, "Accept socket error. Call open before.\n");
    }
	
    return pSock;
}


////////////////////////////////////////
//       Open
/*! Open the socket
*/
BOOL Socket::Open()
{
    BOOL bRes = FALSE;
    // open the server socket
	m_Sock = SDLNet_TCP_Open(m_pIPadd);
    if (m_Sock)
    {
        m_bOnline = true;
        bRes = TRUE;
    }
    return bRes;
}
