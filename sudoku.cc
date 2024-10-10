#include <iostream>
#include <cassert>
#include "sudokuboard.h"

void find_possibilities(sudokuboard & board, size_t r, size_t c,
size_t & possibility_count, int* possibilities)
{

  // Find all allowable numbers at spot (r, c).
  for (int num = 1; num <= 9; num++) {
    char num_char = '0' + num;
    if (board.can_place(r, c, num_char)) {
      possibilities[num - 1] = num;
      possibility_count++;
    }
    // If number is not allowed, use zero as placeholder.
    else {
      possibilities[num - 1] = 0;
    }
  }
}

size_t least_possibilities(sudokuboard & board, size_t & least_r,
size_t & least_c, int* possibilities)
{

  // Declare variables for comparing current spot to most constrained spot.
  int cur_possibilities[9];
  size_t cur_poss_count = 0;
  size_t poss_count = 10;

  // Find most constrained blank spot on board.
  for (size_t r = 0; r < 9; r++){
    for (size_t c = 0; c < 9; c++) {
      // For blank spots, create possibilities list.
      if (board.get(r, c) == '_') {
        cur_poss_count = 0;
        find_possibilities(board, r, c, cur_poss_count, cur_possibilities);
        // If fewer possibilities, update most constrained spot.
        if (cur_poss_count < poss_count) {
          least_r = r;
          least_c = c;
          poss_count = cur_poss_count;
          for (size_t i = 0; i < 9; i++) {
            possibilities[i] = cur_possibilities[i];
          }
        }
      }
    }
  }
  return poss_count;
}

void fill_blanks(sudokuboard & board)
{

  // If the board is solved, exit function.
  if (board.solved()) {
    return;
  }

  // Declare variables for spot with least possibilities.
  int possibilities[9];
  size_t least_r = 0;
  size_t least_c = 0;

  // If there are possibilities at most constrained spot, try them.
  if (least_possibilities(board, least_r, least_c, possibilities)) {
    for(size_t i = 0; i < 9; i++) {
      // Place non-zero possibilities and continue to fill blanks.
      if (possibilities[i]) {
        char least_n = '0' + possibilities[i];
        board.place(least_r, least_c, least_n);
        fill_blanks(board);
        // If board is solved, exit function.
        if (board.solved()) {
          return;
        }
        // Otherwise, remove last item placed.
        else {
          board.remove();
        }
      }
    }
  }
}

int main()
{

  // Make a board.
  sudokuboard board;

  // Solve the sudoku board.
  fill_blanks(board);

  // Output the solved sudoku board.
  board.write(std::cout);

}
