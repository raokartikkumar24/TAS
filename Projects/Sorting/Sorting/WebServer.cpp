#include "stdafx.h"
#include "WebServer.h"


CWebServer::CWebServer()
{
}


CWebServer::~CWebServer()
{
}


void CWebServer::start()
{
	WSADATA ws;
	int nret;

	WSAStartup(0x0101, &ws);

	SOCKET listeningSocket;
	listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listeningSocket == INVALID_SOCKET)
	{
		CLogger::Log(__LINE__, __FILE__, "Could not create listening socket ");
		WSACleanup();

	}

	//fill in address information
	SOCKADDR_IN serverinfo;

	serverinfo.sin_family = AF_INET;
	serverinfo.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverinfo.sin_port = htons(10000);

	//Bind the socket to our local servera address
	nret = bind(listeningSocket, (SOCKADDR*)&serverinfo, sizeof(struct sockaddr));
	if (nret == SOCKET_ERROR)
	{
		std::cout << "could not bind listening socoket \n";
		CLogger::Log(__LINE__, __FILE__, "Could not create listening socket ");
		WSACleanup();
	}

	//make the socket listen
	nret = listen(listeningSocket, 10); // 10 connections at a time?
	if (nret == SOCKET_ERROR)
	{
		CLogger::Log(__LINE__, __FILE__, "could not listen");
		WSACleanup();
	}

	std::cout << "Webserver created at port 10000... \n";
	std::cout << "Listening...\n";
	// wait for the client
	SOCKET commsocket; // communication socket
	commsocket = accept(listeningSocket, NULL, NULL);
	if (commsocket == INVALID_SOCKET)
	{
		CLogger::Log(__LINE__, __FILE__, "could not accept connection request");
		WSACleanup();
	}

	char sendbuffer[256] = "Sorting Web Server";
	char recvbuffer[1024];
	do
	{

		nret = recv(commsocket, recvbuffer, strlen(recvbuffer), 0);
		recvbuffer[nret] = 0;

		if (nret == SOCKET_ERROR)
		{
			CLogger::Log(__LINE__, __FILE__, "could not receive message ");
			WSACleanup();
		}
		else
		{
			CLogger::Log(__LINE__, __FILE__, recvbuffer);
			char timings[25];
			std::cin >> timings;
			nret = send(commsocket, timings, strlen(timings), 0);
			if (nret == SOCKET_ERROR)
			{
				CLogger::Log(__LINE__, __FILE__, "could not send msg to cleint");
				WSACleanup();
			}
		}
	} while (nret > 0);

	closesocket(commsocket);
	closesocket(listeningSocket);

	WSACleanup();

}