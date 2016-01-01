/*  grid.h is a header that defines the generic grid type,
 *  used for the sudoku grid in Sudoker
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
#ifndef SUDOKER_GRID_H_INCLUDED
#define SUDOKER_GRID_H_INCLUDED

#include <stdexcept>

namespace Sudoker
{
	// A 2D matrix of fixed size, defined by w(idth) and h(eight)
	template<const unsigned int w, const unsigned int h>
	class Grid
	{
	public:
		const unsigned int width = w;
		const unsigned int height = h;

	private:
		int _content[w*h];

	public:
		struct Position
		{
			unsigned int x;
			unsigned int y;

			unsigned int index() const
			{
				return x + (y * w);
			}

			bool operator==(const Position& other) const
			{
				if (x == other.x && y == other.y)
				{
					return true;
				}
				return false;
			}
			bool operator!=(const Position& other) const
			{
				if (x == other.x && y == other.y)
				{
					return false;
				}
				return true;
			}

			Position(const unsigned int x, const unsigned int y) :
				x(x), y(y)
			{
				if (x > w)
				{
					throw(std::invalid_argument("Grid::Position::Position(x)"));
				}
				if (y > h)
				{
					throw(std::invalid_argument("Grid::Position::Position(y)"));
				}
			}
		};

		Position position(const unsigned int x, const unsigned int y) const { return Position(x, y); } // position factory
		int get(const Position position) const { return _content[position.index()]; } // get value in position
		void set(const Position position, const int value) { _content[position.index()] = value; } // set value to position

		int operator[](const Position position) const { return get(position); }
		Grid<w, h>& operator=(Grid<w, h> other)
		{
			for (int i = 0; i < w*h; ++i)
			{
				_content[i] = other._content[i];
			}
			return *this;
		}
		bool operator==(const Grid<w, h>& other) const
		{
			for (unsigned int y = 0; y < h; ++y)
			{
				for (unsigned int x = 0; x < w; ++x)
				{
					if (get(Position(x, y)) != other.get(Position(x, y)))
					{
						return false;
					}
				}
			}
			return true;
		}

		Grid()
		{
			for (int i = 0; i < w*h; ++i)
			{
				_content[i] = 0;
			}
		}
	};
}

#endif
