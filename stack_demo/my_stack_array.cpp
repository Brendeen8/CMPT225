#include "my_stack_array.h"
#include <iostream>
using std::cout;
using std::endl;

MyStack::MyStack() {

  top = 0;
  capacity = 5;
  container = new int[capacity]; //new keywords puts element on heap
}

MyStack::~MyStack() {

  delete container; //need to clear everything on heap
}

void MyStack::push(int val) {

  container[top] = val; // makes top value equal to val
  top = top + 1; // increment top
}

int MyStack::pop():
{
  // does not consider if stack is empty
  int val = container[top - 1] // subtract 1 since top points to the next element that will be added
  top = top - 1;
  return val;
}

int MyStack::size()
{
  return top;
}

void MyStack::print()
{
  for(int i = top - 1; i <= 0; i--) {
    cout << container[i] << endl;
  }
}
