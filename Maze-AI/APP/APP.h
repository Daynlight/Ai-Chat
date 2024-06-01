#pragma once
#include "MAZE.h"
#include "AI.h"
#include <Windows.h>
#include <cstdio>

namespace MAI {
	class APP
	{
	public:
		APP();
		void Loop();
		~APP();

	private:
		MAI::MAZE* MAZE;
		MAI::AI* AI;
		bool Close = 0;
	};
}
