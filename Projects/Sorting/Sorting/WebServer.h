#pragma once
#include <Windows.h>
#include <winsock.h>
#include <stdio.h>
#include <iostream>
#include "Logger.h"
class CWebServer
{
public:
	CWebServer();
	~CWebServer();

	void start();

};

