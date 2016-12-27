# Sudoker
C++ library for Sudoku

# Features:
* Generating puzzles by difficulty
* Solving (some) puzzles
* Checking if a given state is legal

# Usage:
    using namespace Sudoker;
    int main() {
      auto medium_grid = Sudoker::generateUnique(Sudoker::DIFFICULTY_MEDIUM);
      auto solved_grid = solve(medium_grid);
      
      return 0;
    }
    
