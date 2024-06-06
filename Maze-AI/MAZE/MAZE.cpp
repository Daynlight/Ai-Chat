#include "MAZE.h"

MAI::MAZE::MAZE() {}

void MAI::MAZE::GenerateMaze()
{
	Map.fill(0);
	//[Generate Start And End]
	int Start = floor(Row * Columns / 2) + floor(Row / 2);
	int End = Start + 8 + Row * 4;

	//[Create Route]
	int Current = Start;
	int Move = 0;
	int LastMove = 0;
	int Temp = 0;
	int Try = 0;

	while (Current != End) {
		Move = GenerateRandom(0, 3);

		if (Move == 0) Move = Row;
		else if (Move == 1) Move = 1;
		else if (Move == 2) Move = -Row;
		else if (Move == 3) Move = -1;

		if (Current + Move > 0 && Current + Move < Row * Columns  &&
			Current + 2 * Move > 0 && Current + 2 * Move < Row * Columns &&
			((abs(Move) != Row && floor((Current + 2 * Move) / Row) == floor(Current / Row)) || abs(Move) == Row) &&
			((Map[Current + Move] != 1 && Map[Current + 2 * Move] != 1)) || Try > CreateEffort) {


			Current = Current + Move;
			Map[Current] = 1;
			Current = Current + Move;
			Map[Current] = 1;

			LastMove = Move;

			////[Debug]
			//Map[Start] = 2;
			//Map[End] = 3;
			//Map[Current] = 5;
			//system("cls");
			//PrintMaze();
			//std::cout << Try;
			//Map[Current] = 1;
		}

		Try++;
		if (Current + Move > 0 && Current + Move < Row * Columns &&
			Current + 2 * Move > 0 && Current + 2 * Move < Row * Columns &&
			Map[Current + Move] != 1 && Map[Current + 2 * Move] != 1) Try = 0;

		//[GoBack to Start]
		if (Try == CreateEffort) {
			Current = Start;
		};
	}

	//[Noise]
	int Counter = 0;
	while (Try <= CreateEffort && Counter < floor(Row * Columns * (Noise / 100))) {

		Map[GenerateRandom(0, Row * Columns - 1)] = 1;
		Counter++;
	}

	//[Start and End]
	Map[Start] = 2;
	Map[End] = 3;
}

void MAI::MAZE::GetMoves(int Position)
{

}

void MAI::MAZE::PrintMaze()
{
	std::cout << "\n";
	for (int i = 0; i < Row * Columns; i++) {
		if ((i % Row) == 0) std::cout << "\n";
		if (Map[i] == 0) std::cout << (char)254u << " ";
		else if (Map[i] == 2) std::cout << "S ";
		else if (Map[i] == 3) std::cout << "E ";
		else if (Map[i] == 1) std::cout << "  ";
		//[Debug]
		else if (Map[i] == 5) std::cout << "O ";
	}
	std::cout << "\n";
}

MAI::MAZE::~MAZE() {}

int MAI::MAZE::GenerateRandom(int Min, int Max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(Min, Max); // define the range

	return distr(gen);
}
