#include "MAZE.h"

MAI::MAZE::MAZE(const size_t& Size) : Map(Size, 0) {}

void MAI::MAZE::GenerateMaze()
{
	//[Generate Start And End]
	Mat::Vec2<int> Start = Mat::Vec2<int>(0);
	Mat::Vec2<int> End = Mat::Vec2<int>(5);

	//[Create Route]
	Mat::Vec2<int> CurrentPosition = Start;

	while (CurrentPosition != End) {



	}

	//[Place Start and End]
	Map[Start.x + Start.y * sqrt(Map.size())] = 2;
	Map[End.x + End.y * sqrt(Map.size())] = 3;
}

void MAI::MAZE::GetMoves(Mat::Vec2<int> Position)
{

}

void MAI::MAZE::PrintMaze()
{
	std::cout << "\n";
	for (int i = 0; i < Map.size(); i++) {
		if ((i % static_cast<int>((sqrt(Map.size())))) == 0) std::cout << "\n";
		if (Map[i] == 0) std::cout << (char)254u << " ";
		else if (Map[i] == 2) std::cout << "S ";
		else if (Map[i] == 3) std::cout << "E ";
		else if (Map[i] == 1) std::cout << "  ";
	}
	std::cout << "\n";
}

MAI::MAZE::~MAZE() {}

int MAI::MAZE::GenerateRandom(int Min, int Max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(Min, Max);

	return distr(gen);
}
