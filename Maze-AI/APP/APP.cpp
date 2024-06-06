#include "APP.h"

MAI::APP::APP()
	:MAZE(new MAI::MAZE(pow(50, 2))), AI(new MAI::AI())
{
	MAZE->GenerateMaze();
	MAZE->PrintMaze();
	
	//[OnLoad]

}

void MAI::APP::Loop()
{
	//[Loop]
	//while (!Close) {



	//}
}

MAI::APP::~APP()
{
	//[OnClose]
	delete MAZE;
	delete AI;
}
