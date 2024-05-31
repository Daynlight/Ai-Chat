#include "APP.h"

APP::APP()
	:MAZEComponent(new MAZE()), AIComponent(new AI()) {}

void APP::Loop()
{
}

APP::~APP()
{
	delete MAZEComponent;
	delete AIComponent;
}
