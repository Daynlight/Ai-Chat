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
		const float Noise = 20.0f;
		const int CreateEffort = 10;
		const int Row = 50;
		const int Columns = 50;
		std::array<short, 50 * 50> Map;

		int GenerateRandom(int Min = 0, int Max = 0);
	};
}
