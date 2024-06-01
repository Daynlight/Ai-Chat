#include "APP.h"

APP::APP()
	:MAZEComponent(new MAZE()), AIComponent(new AI()) 
{
	printf("To Exit Press 'Esc'");
}

void APP::Loop()
{
	while (!Close) {




		if(GetKeyState(0x1B)) Close = !GetKeyState(0x1B);
	}
}

APP::~APP()
{
	delete MAZEComponent;
	delete AIComponent;
}
