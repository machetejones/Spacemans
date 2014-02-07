#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "SDL_net.h"
#include <string>

using namespace std;

class Socket{
public:
	UDPsocket uSock;
	IPaddress srvadd;
	Socket();
	~Socket();
	void init_socket();
	void send_data(string);
};

#endif
