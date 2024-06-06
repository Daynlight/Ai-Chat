#include "MAZE.h"

MAI::MAZE::MAZE(const size_t& Size) : Map(Size, 0) {}

void MAI::MAZE::GenerateMaze()
{
	//[Generate Start And End]
	Mat::Vec2<int> Start = Mat::Vec2<int>(0);
	Mat::Vec2<int> End = Mat::Vec2<int>(0);

	while (Start == End || End % 2 != 0 || Start.y % 2 != 0) {
		Start.x = GenerateRandom(2, sqrt(Map.size()) - 3);
		Start.y = GenerateRandom(2, sqrt(Map.size()) - 3);
		End.x = GenerateRandom(2, sqrt(Map.size()) - 3);
		End.y = GenerateRandom(2, sqrt(Map.size()) - 3);
	}


	//[Create Route]
	Mat::Vec2<int> CurrentPosition = Start;

	while (CurrentPosition.Distance(End) > 1) {
		//[Genereate Move]
		short MovePropability = GenerateRandom(0, 100);
		Mat::Vec2<int> Move = Mat::Vec2<int>(0);
		switch (MovePropability < GoodMovePorpability) {
			case true: // Good
				if (CurrentPosition.x - End.x == 0) {
					if (CurrentPosition.y < End.y) Move.y = 2;
					if (CurrentPosition.y > End.y) Move.y = -2;
				}
				else {
					if (CurrentPosition.x < End.x) Move.x = 2;
					if (CurrentPosition.x > End.x) Move.x = -2;
				}
				break;
			default: // Random
				switch (GenerateRandom(0, 3)) {
					case 0: //Top
						Move.y = 2;
						break;
					case 1: //Right
						Move.x = 2;
						break;
					case 2: //Bottom
						Move.y = -2;
						break;
					case 3: //Left
						Move.x = -2;
						break;
				}	
				break;
		}


		if (CurrentPosition.x + Move.x > 0 && CurrentPosition.x + Move.x < sqrt(Map.size()) - 1 &&
			CurrentPosition.y + Move.y > 0 && CurrentPosition.y + Move.y < sqrt(Map.size()) - 1) {

			CurrentPosition += Move / 2;
			Map[CurrentPosition.x + CurrentPosition.y * sqrt(Map.size())] = 1;
			CurrentPosition += Move / 2;
			Map[CurrentPosition.x + CurrentPosition.y * sqrt(Map.size())] = 1;

			Map[Start.x + Start.y * sqrt(Map.size())] = 2;
			Map[End.x + End.y * sqrt(Map.size())] = 3;
			system("cls");
			PrintMaze();
		}
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
