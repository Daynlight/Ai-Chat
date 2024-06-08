#pragma once
#include "Mat-Cpp/Mat.h"
#include <random>
#include <vector>
#include <iostream>

namespace MAI {
	class MAZE
	{
	public:
		MAZE(const size_t& Size = 100);
		void GenerateMaze();
		void GetMoves(Mat::Vec2<int> Position = Mat::Vec2<int>(0));
		void PrintMaze();
		~MAZE();

	private:
		//[Settings]
		std::vector<int> Map;
		const short GoodMovePorpability = 30;
		const short ForceEndRadPer = 10;
		const short ForceEndPorpoability = 85;

		int GenerateRandom(int Min = 0, int Max = 0);
	};
}
