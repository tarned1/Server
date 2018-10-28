#include "Server.h"

Server::Server()
{
	WSADATA wsData;

	WORD verb = MAKEWORD(2, 2);
	int wsOK = WSAStartup(verb, &wsData);

	if (wsOK != 0) {
		throw 0;
	}

	listening = socket(AF_INET, SOCK_STREAM, 0);

	if (listening == INVALID_SOCKET)
		throw 1;
	sockaddr_in hint;
	
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);

	sockaddr_in Client;
	int clientSize = sizeof(Client);

	ClientS = accept(listening, (sockaddr*)&Client, &clientSize);

	char host[NI_MAXHOST];
	char service[NI_MAXHOST];

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);

	if (getnameinfo((sockaddr*)&Client, sizeof(Client), host, NI_MAXHOST, service, NI_MAXHOST, 0) == 0) {
		cout << host << " connected on port " << service << endl;
	}
	else{
		inet_ntop(AF_INET, &Client.sin_addr, host, NI_MAXHOST);
		cout << host << " connexted on port " << ntohs(Client.sin_port) << endl;
	}
}

Server::~Server()
{
	closesocket(listening);
	closesocket(ClientS);
	WSACleanup();
}

SOCKET Server::get_ClientS() const
{
	return ClientS;
}
