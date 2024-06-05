#include "MAZE.h"

MAI::MAZE::MAZE() {}

void MAI::MAZE::GenerateMaze()
{
	Map.fill(0);
	//[Generate Start And End]
	int Start = GenerateRandom(0, Row * Columns - 1);
	int End = Start + GenerateRandom(-Start + 1, Row * Columns - Start - 1);

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
			Map[Current + Move] != 1 && Map[Current + 2 * Move] != 1) {

			if (abs(Move) != Row && floor((Current + Move) / Row) != floor(Current / Row))
			{
				if (Move < 0) Current += Row;
				else if (Move > 0) Current -= Row;
			}

			Current = Current + Move;
			LastMove = Move;
			Map[Current] = 1;
			Try = 0;
		}

		Try++;

		if(Try > CreateEffort) break;
	}

	//[Noise]
	int Counter = 0;
	while (Try <= CreateEffort && Counter < floor(Row * Columns * (Noise / 100))) {

		Map[GenerateRandom(0, Row * Columns - 1)] = 1;
		Counter++;
	}

	Map[Start] = 2;
	Map[End] = 3;

	if (Try > CreateEffort) {
		Try = 0;
		GenerateMaze();
	}
}

void MAI::MAZE::GetMoves(int Position)
{

}

void MAI::MAZE::PrintMaze()
{
	for (int i = 0; i < Row * Columns; i++) {
		if ((i % Row) == 0) std::cout << "\n";
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
