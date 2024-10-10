// FILE: sudokuboard.h
// AUTHOR: Zoe Carovano
// DATE: Spring 2020

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <iostream>
#include "stack.h"

class sudokuboard {
 public:
  sudokuboard();

  bool can_place(size_t r,size_t c,char n) const;
  // PRE: 0 <= r,c < 9
  // Return true if position (r,c) is blank and
  // n does not appear on this board in the given row, column,
  // or box containing (r,c)

  void place(size_t r,size_t c, char n);
  // PRE: can_place(r, c, n)
  // make the cell at position (r,c) equal to n and add (r, c) to stack.

  bool solved() const;
  // Return true if no cell is blank.

  void write(std::ostream & ostr) const;
  // Print this board on the given output stream

  char get(size_t r,size_t c) const;
  // PRE: 0 <= r,c < 9
  // Return the character at position (r,c)

  void remove();
  // PRE: 0 <= r,c < 9; at(r,c) != '_'
  // Retrieve and remove (r, c) from stack and make value at (r, c) '_'.

 private:
  std::string rows[9];
  stack s;

};


#endif
