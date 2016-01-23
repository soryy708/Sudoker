#ifndef SUDOKER_GENERATOR_H_INCLUDED
#define SUDOKER_GENERATOR_H_INCLUDED

#include <Sudoker/sudoku_grid.h>

namespace Sudoker
{
	enum Difficulty
	{
		DIFFICULTY_EASY = 51,
		DIFFICULTY_MEDIUM = 47,
		DIFFICULTY_HARD = 17
	};

	UniquelySolvableSudokuGrid generateUnique(Difficulty difficulty);
}

#endif
