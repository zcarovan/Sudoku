// FILE: sudokuboard.cc
// AUTHOR: Zoe Carovano
// DATE: Spring 2020

#include "sudokuboard.h"
#include "stack.h"
#include <cassert>
#include <iostream>
#include <cmath>

#define DIM 9


sudokuboard::sudokuboard()
{

  // Fill board from user input.
  std::string input_row = "";
  for (int i=0;i<DIM;i++) {
    rows[i] = "";
    std::cin >> rows[i];
  }
}

bool sudokuboard::can_place(size_t r,size_t c,char n) const
{

  // Check row and column for given number.
  for (size_t i = 0; i < DIM; i++) {
    if (n == get(r, i)) {
      return false;
    }
    if (n == get(i, c)) {
      return false;
    }
  }

  // Check box for given number.
  for (size_t row = 0; row < 3; row++) {
    for (size_t col = 0; col < 3; col++) {
      if (rows[r + (row - r % 3)][c + (col - c % 3)] == n) {
        return false;
      }
    }
  }
  // If no conflicts, number can be placed there.
  return true;
}


bool sudokuboard::solved() const
{
  // This method provided by Professor Campbell
  for (int i=0;i<DIM;i++)
    if (rows[i].find('_')<(size_t)DIM)
      return false;
  return true;
}

void sudokuboard::write(std::ostream & ostr) const
{
  // This method provided by Professor Campbell
  for (int i=0;i<DIM;i++)
    ostr << rows[i] << std::endl;
}

void sudokuboard::place(size_t r,size_t c,char n)
{

  // Place number at given spot and save coordinates to stack.
  rows[r][c] = n;
  s.push(r);
  s.push(c);

}

char sudokuboard::get(size_t r,size_t c) const
{

  // Return element at the given row and column.
    return rows[r][c];
}

void sudokuboard::remove()
{

  // Read and remove last spot from stack and remove number from that spot.
  int c = s.top(); s.pop();
  int r = s.top(); s.pop();
  rows[r][c] = '_';
}
