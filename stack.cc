#include <iostream>
#include <cassert>
#include "stack.h"

stack::node::node() {}  // node constructor leaving fields uninitialized

stack::node::node(const element & item, node * n) {
  data = item;
  next = n;
}

stack::stack() {
  _top = nullptr;
}

void stack::push(const element & e)
{

  // Add element to top of stack.
  _top = new node(e, _top);
}

void stack::pop()
{

  // If stack not empty, take top element off stack.
  if (!empty()) {
    _top = _top -> next;
  }
}

stack::element stack::top() const
{

  // Return top element of stack.
  return _top -> data;
}

bool stack::empty() const
{

  // Check if stack is empty.
  return _top == nullptr;
}
