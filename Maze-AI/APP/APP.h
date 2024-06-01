#pragma once
#include "MAZE.h"
#include "AI.h"
#include <Windows.h>
#include <cstdio>

class APP
{
public:
	APP();
	void Loop();
	~APP();

private:
	MAZE* MAZEComponent;
	AI* AIComponent;
	bool Close = 0;
};

