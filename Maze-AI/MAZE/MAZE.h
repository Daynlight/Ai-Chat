#pragma once
#include <array>

class MAZE
{
public:
	MAZE();
	void GenerateMaze();
	~MAZE();

private:
	std::array<short, 10 * 10> MAZEMap;

};

