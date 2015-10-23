/*  sudoku_grid.cpp is a source file that defines the SudokuGrid class
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
#include "sudoku_grid.h"

namespace Sudoker
{
	void SudokuGrid::set(const Grid<9, 9>::Position position, const int value)
	{
		if (value > 9)
		{
			throw(std::invalid_argument("SudokuGrid::set(value)"));
		}
		else
		{
			Grid<9, 9>::set(position, value);
		}
	}

	bool SudokuGrid::isValid() const
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			for (unsigned int x = 0; x < width; ++x)
			{
				if ((isValid(position(x, y)) == false) && (get(position(x, y)) != 0))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool SudokuGrid::isValid(const Grid<9, 9>::Position position) const
	{
		return isValid(position, get(position));
	}
	
	bool SudokuGrid::isValid(const Grid<9, 9>::Position position, const int value) const
	{
		if (value != 0)
		{
			unsigned int x;
			unsigned int y;

			for (x = 0; x < width; ++x) // test row
			{
				if (get(this->position(x, position.y)) == value && this->position(x, position.y) != position)
				{
					return false;
				}
			}
			for (y = 0; y < height; ++y) // test column
			{
				if (get(this->position(position.x, y)) == value && this->position(position.x, y) != position)
				{
					return false;
				}
			}
			for (x = 0; x < 3; ++x) // test square
			{
				for (y = 0; y < 3; ++y)
				{
					const unsigned int square_x = position.x / 3;
					const unsigned int square_y = position.y / 3;
					const auto sample_position = this->position(square_x * 3 + x, square_y * 3 + y);
					if (sample_position != position && get(sample_position) == value)
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	bool SudokuGrid::isFull() const
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			for (unsigned int x = 0; x < width; ++x)
			{
				if (get(position(x, y)) == 0)
				{
					return false;
				}
			}
		}
		return true;
	}
}
