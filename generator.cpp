#include "generator.h"

namespace Sudoker
{
	UniquelySolvableSudokuGrid generateUnique(Difficulty difficulty)
	{
		UniquelySolvableSudokuGrid grid;

		// Placeholder implementation
		grid.set(grid.position(7, 0), 8);
		grid.set(grid.position(0, 1), 9);
		grid.set(grid.position(3, 1), 1);
		grid.set(grid.position(4, 1), 3);
		grid.set(grid.position(5, 1), 7);
		grid.set(grid.position(8, 1), 6);
		grid.set(grid.position(2, 2), 7);
		grid.set(grid.position(5, 2), 9);
		grid.set(grid.position(7, 2), 2);
		grid.set(grid.position(0, 4), 5);
		grid.set(grid.position(2, 4), 6);
		grid.set(grid.position(3, 4), 4);
		grid.set(grid.position(5, 4), 2);
		grid.set(grid.position(0, 5), 1);
		grid.set(grid.position(1, 5), 2);
		grid.set(grid.position(2, 5), 3);
		grid.set(grid.position(2, 6), 1);
		grid.set(grid.position(4, 6), 2);
		grid.set(grid.position(5, 6), 3);
		grid.set(grid.position(6, 6), 8);
		grid.set(grid.position(7, 6), 4);
		grid.set(grid.position(0, 7), 2);
		grid.set(grid.position(1, 7), 9);
		grid.set(grid.position(2, 7), 8);
		grid.set(grid.position(3, 7), 7);
		grid.set(grid.position(4, 7), 4);
		grid.set(grid.position(5, 7), 1);
		grid.set(grid.position(6, 7), 3);
		grid.set(grid.position(7, 7), 6);
		grid.set(grid.position(0, 8), 7);
		grid.set(grid.position(3, 8), 6);
		grid.set(grid.position(4, 8), 8);
		grid.set(grid.position(5, 8), 5);
		grid.set(grid.position(6, 8), 2);
		grid.set(grid.position(7, 8), 9);

		return grid;
	}
}
