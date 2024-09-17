#include "my_stack_array.h"
#include <iostream>
using std::cout;
using std::endl;

MyStack::MyStack() { // define private variables in default contructor

  top = 0;
  capacity = 5;
  container = new int[capacity]; // new keyword puts element on heap
}

MyStack::~MyStack() {

  delete container; //need to clear everything on heap
}

void MyStack::push(int val) { // insert at top of stack

  container[top] = val; // makes top value equal to given val
  top = top + 1; // increment top
}

int MyStack::pop(): // remove and return top item
{
  // does not consider if stack is empty
  int val = container[top - 1] // subtract 1 since top points to the next element that will be added
  top = top - 1; // deincrement top
  return val;
}

int MyStack::size() // top is the same value of size but we need to use this since top is private
{
  return top;
}

void MyStack::print()
{
  for(int i = top - 1; i <= 0; i--) {
    cout << container[i] << endl;
  }
}
