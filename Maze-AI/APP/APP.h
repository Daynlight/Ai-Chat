#pragma once
#include "MAZE.h"
#include "AI.h"

class APP
{
public:
	APP();
	void Loop();
	~APP();

private:
	MAZE* MAZEComponent;
	AI* AIComponent;

};

