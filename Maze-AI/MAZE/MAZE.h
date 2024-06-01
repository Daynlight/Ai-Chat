#pragma once
#include <array>
#include <random>
#include <iostream>

namespace MAI {
	class MAZE
	{
	public:
		MAZE();
		void GenerateMaze();
		void GetMoves(int Position = 0);
		void PrintMaze();
		~MAZE();

	private:
		//[Settings]
		const float Ammount = 0.70;
		const int Row = 10;
		const int Columns = 10;
		std::array<short, 10*10> Map;

		int GenerateRandom(int Min = 0, int Max = 0);
	};
}
