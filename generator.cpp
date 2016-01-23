#include <vector>
#include "generator.h"
#include "solver.h"

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

	struct RemovedNumber
	{
		int value;
		SudokuGrid::Position position;

		RemovedNumber(const int number, SudokuGrid::Position position) :
			value(number),
			position(position)
		{
		}
	};
	void removeNumbers(SudokuGrid& grid, const Difficulty difficulty)
	{
		const int grid_size = 9 * 9;
		std::vector<RemovedNumber> removed;

		int fails = 0;
		for (int i = 0; i < grid_size - difficulty; ++i)
		{
			if (fails >= grid_size / 2)
			{
				const SudokuGrid::Position pos(removed.back().position);
				const int value = removed.back().value;
				removed.pop_back();
				grid.set(pos, value);
				--i;
				fails = 0;
			}
			else
			{
				const SudokuGrid::Position pos(rand() % grid.width, rand() % grid.height);
				const int value = grid.get(pos);
				if (value == 0)
				{
					--i;
					continue;
				}
				grid.set(pos, 0);
				if (grid == solve(*((UniquelySolvableSudokuGrid*)&grid)))
				{
					grid.set(pos, value);
					--i;
					++fails;
				}
				else
				{
					removed.push_back(RemovedNumber(value, pos));
					fails = 0;
				}
			}
		}
	}

	UniquelySolvableSudokuGrid generateUnique(const Difficulty difficulty)
	{
		UniquelySolvableSudokuGrid grid;

		fillGrid(grid);
		randomizeNumbers(grid);
		removeNumbers(grid, difficulty);
		switch (rand() % 3)
		{
		case(0) :
			grid.flip(SudokuGrid::FLIP_HORIZONTALLY);
			break;
		case(1) :
			grid.flip(SudokuGrid::FLIP_VERTICALLY);
			break;
		case(2) :
			grid.flip(SudokuGrid::FLIP_BOTH);
			break;
		}

		return grid;
	}
}
