/*  sudoku_grid.h is a header that declares the sudoku grid
 *	Copyright(C) 2015  Ivan Rubinson
 *
 *	This program is free software : you can redistribute it and / or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SUDOKER_SUDOKU_GRID_H_INCLUDED
#define SUDOKER_SUDOKU_GRID_H_INCLUDED

#include "grid.h"

namespace Sudoker
{
	// SudokuGrid is a 9x9 grid. Empty cells are filled with 0. Cells can contain any integer between 0 and 9.
	class SudokuGrid : public Grid<9, 9>
	{
	public:
		void set(const Grid<9, 9>::Position position, const int value); // accepts only positions that fit a 9x9 grid

		bool isValid() const; // runs on the whole grid, checking if every position is valid
		bool isValid(const Grid<9, 9>::Position position) const; // runs on a particular position in the grid, checking if valid
		bool isValid(const Grid<9, 9>::Position position, const int value) const; // returns true if placing value in position is valid
		bool isFull() const; // returns true if grid contains no zeros (puzzle is solved)
	};

	class UniquelySolvableSudokuGrid : public SudokuGrid {};

	bool isUniquelySolvable(const SudokuGrid);
}

#endif
