#ifndef SERVER_H
#define SERVER_H

#include<iostream>
#include<string.h>
#include<WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

class Server {
	SOCKET ClientS;
	SOCKET listening;

public:
	Server();
	~Server();

	SOCKET get_ClientS() const;
};
#endif
