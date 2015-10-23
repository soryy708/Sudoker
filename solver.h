#ifndef SUDOKER_SOLVER_H_INCLUDED
#define SUDOKER_SOLVED_H_INCLUDED

#include <Sudoker/sudoku_grid.h>

namespace Sudoker
{
	SudokuGrid solve(const UniquelySolvableSudokuGrid grid);
}

#endif
