#include "generator.h"

namespace Sudoker
{
	void fillGrid(SudokuGrid& grid)
	{
		for (unsigned int y = 0; y < grid.height; ++y)
		{
			for (unsigned int x = 0; x < grid.width; ++x)
			{
				const SudokuGrid::Position pos(SudokuGrid::Position(x, y));

				bool found = false;
				for (int val = grid.get(pos) + 1; val <= 9 && !found; ++val)
				{
					if (grid.isValid(pos, val))
					{
						grid.set(pos, val);
						found = true;
					}
				}

				if (!found)
				{
					grid.set(pos, 0);
					x -= 2;
				}

				if (x < 0)
				{
					y -= 1;
					x += 8;
				}
				if (y < 0)
				{
					y = -1;
				}
			}
		}
	}

	void randomizeNumbers(SudokuGrid& grid)
	{
		const int table_size = 9;
		int table[table_size];
		for (unsigned int i = 0; i < table_size; ++i)
		{
			table[i] = (rand() % 9) + 1;
			for (unsigned int j = 0; j < i; ++j)
			{
				if (table[j] == table[i])
				{
					--i;
					break;
				}
			}
		}

		for (unsigned int y = 0; y < grid.height; ++y)
		{
			for (unsigned int x = 0; x < grid.width; ++x)
			{
				const SudokuGrid::Position pos(x, y);
				grid.set(pos, table[grid.get(pos) - 1]);
			}
		}
	}

	UniquelySolvableSudokuGrid generateUnique(Difficulty difficulty)
	{
		UniquelySolvableSudokuGrid grid;

		fillGrid(grid);
		randomizeNumbers(grid);

		return grid;
	}
}
