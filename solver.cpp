#include "solver.h"

namespace Sudoker
{
	struct BanArray
	{
		bool array[10];

		int uniqueUnbanned()
		{
			int unique = 0;
			int count = 0;
			for (int i = 0; i < 10; ++i)
			{
				if (array[i] == false)
				{
					unique = i;
					++count;
				}
			}
			if (count == 1)
			{
				return unique;
			}
			return 0;
		}

		BanArray()
		{
			for (int i = 0; i < 10; ++i)
			{
				array[i] = false;
			}
		}
	};

	SudokuGrid solve(const UniquelySolvableSudokuGrid grid)
	{
		SudokuGrid solution = grid;

		bool changed = false;
		do
		{
			changed = false;
			for (unsigned int y = 0; y < solution.height; ++y)
			{
				for (unsigned int x = 0; x < solution.width; ++x)
				{
					if (solution.get(solution.position(x, y)) == 0)
					{
						BanArray ban;
						unsigned int test_x;
						unsigned int test_y;

						for (test_x = 0; test_x < solution.width; ++test_x) // test row
						{
							ban.array[solution.get(solution.position(test_x, y))] = true;
						}
						for (test_y = 0; test_y < solution.height; ++test_y) // test column
						{
							ban.array[solution.get(solution.position(x, test_y))] = true;
						}
						for (test_x = 0; test_x < 3; ++test_x) // test square
						{
							for (test_y = 0; test_y < 3; ++test_y)
							{
								const unsigned int square_x = x / 3;
								const unsigned int square_y = y / 3;
								const auto sample_position = solution.position(square_x * 3 + test_x, square_y * 3 + test_y);
								ban.array[solution.get(sample_position)] = true;
							}
						}

						int unique = ban.uniqueUnbanned();
						if (unique != 0)
						{
							if (solution.isValid(solution.position(x, y), unique))
							{
								solution.set(solution.position(x, y), unique);
								changed = true;
							}
							else
							{
								throw(std::runtime_error("Solve failed miserably"));
							}
						}
					}
				}
			}
		} while (changed);

		if (solution.isFull() == false)
		{
			throw(std::runtime_error("Grid has no unique solution"));
		}

		return solution;
	}
}
