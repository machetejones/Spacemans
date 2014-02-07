#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SDL.h"
#include "SDL_net.h"
#include "Network.h"

using namespace std;
 
Socket::Socket(){

}
Socket::~Socket(){

}

void Socket::init_socket()
{
	SDLNet_Init();
	uSock = SDLNet_UDP_Open(0);
	SDLNet_ResolveHost(&srvadd, "192.168.2.183", 4000);
}

void Socket::send_data(string packet_data)
{
	char data[128]; 
	strcpy(data,packet_data.c_str());

	UDPpacket *p = SDLNet_AllocPacket(512);

	memcpy(p->data, data, p->maxlen);
	p->len = strlen((char *)p->data) + 1;

	p->address.host = srvadd.host;	
	p->address.port = srvadd.port;	
	SDLNet_UDP_Send(uSock, -1, p);
	SDLNet_FreePacket(p);
}

