#include "MAZE.h"

MAI::MAZE::MAZE() {}

void MAI::MAZE::GenerateMaze()
{
	Map.fill(0);
	int Start = GenerateRandom(0, Map.size() - 1);
	int End = GenerateRandom(0, Map.size() - 1);
	if (Start != End) {
		for (int i = 0; i < Map.size() * Ammount; i++) {
			int Place = GenerateRandom(0, Map.size() - 1);
			Map[Place] = 1;
		}
		Map[Start] = 2;
		Map[End] = 3;
	}
	else GenerateMaze();
}

void MAI::MAZE::GetMoves(int Position)
{

}

void MAI::MAZE::PrintMaze()
{
	for (int i = 0; i < Map.size(); i++) {
		if ((i % 10) == 0) std::cout << "\n";
		if (Map[i] == 0) std::cout << (char)254u << " ";
		else if (Map[i] == 2) std::cout << "S ";
		else if (Map[i] == 3) std::cout << "E ";
		else if (Map[i] == 1) std::cout << "  ";
	}
}

MAI::MAZE::~MAZE() {}

int MAI::MAZE::GenerateRandom(int Min, int Max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(Min, Max); // define the range

	return distr(gen);
}
