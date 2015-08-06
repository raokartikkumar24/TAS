#pragma once
#include <Windows.h>
#include <winsock.h>
#include <stdio.h>
#include <iostream>

class CClient
{
public:
	CClient();
	~CClient();

	void TalkToServer();
	void displayTimings(char timings[]);
};

