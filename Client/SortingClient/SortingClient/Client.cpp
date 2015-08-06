#include "stdafx.h"
#include "Client.h"


CClient::CClient()
{
}


CClient::~CClient()
{
}

void CClient::TalkToServer()
{
	WSADATA ws;
	int nret;

	WSAStartup(0x0101, &ws);

	SOCKET commsocket;
	commsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (commsocket == INVALID_SOCKET)
	{
		std::cout << "Could not create comms socket \n";
		WSACleanup();
	}

	SOCKADDR_IN serverinfo;
	serverinfo.sin_family = AF_INET;
	serverinfo.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	serverinfo.sin_port = htons(10000);

	nret = connect(commsocket, (LPSOCKADDR)&serverinfo, sizeof(struct sockaddr));
	if (nret == SOCKET_ERROR)
	{
		std::cout << "Could not connect to the server \n";
		WSACleanup();
	}

	char sendbuffer[25];
	char recvbuffer[25];

	do
	{
		std::cin >> sendbuffer;

		nret = send(commsocket, sendbuffer, strlen(sendbuffer), 0);

		if (nret == SOCKET_ERROR)
		{
			std::cout << "Could not send bytes to the server \n";
			WSACleanup();
		}


		nret = recv(commsocket, recvbuffer, 25, 0);
		if (nret == SOCKET_ERROR)
		{
			std::cout << "Could not connect to the server \n";
			WSACleanup();
		}
		else if (nret == 0)
		{
			std::cout << "Conncetion closed \n";
		}
		else
		{
			std::cout << "Received : " << recvbuffer << "from the server \n";
		}
	} while (nret > 0);
	closesocket(commsocket);
	WSACleanup();
}