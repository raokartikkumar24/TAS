// SortingClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	CClient client;
	client.TalkToServer();

	return 0;
}

