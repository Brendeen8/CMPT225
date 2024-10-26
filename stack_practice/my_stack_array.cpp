#include <iostream>
#include "my_stack_array.h"
using std::cout;
using std::endl;

MyStackArray::MyStackArray() {
  int capacity = 10;
  int* container = new int[capacity];
  int top = 0;
}

MyStackArray::MyStackArray(int capacity) {
  this->capacity = capacity;
  top = 0;
  container = new int[capacity];
}
MyStackArray::~MyStackArray() {
  delete[] container;
}

void MyStackArray::push(int val) {
  if(top >= capacity) {
    increaseSize();
  }
  this->container[top] = val;
  this->top++;
  return;
}

int MyStackArray::pop() {
  int val = this->container[this->top-1];
  this->top--;
  return val;
}

int MyStackArray::size() {
  return this->top;
}

void MyStackArray::print() {
  for(int i = 0; i < top; i++) {
    cout << this->container[i] << endl;
  }
}
void MyStackArray::increaseSize() {
  int newCapacity = capacity*2;
  int* newContainer = new int[newCapacity];

  for(int i = 0; i < top; i++) {
    newContainer[i] = container[i];
  }

  delete[] container;

  container = newContainer;
  capacity = newCapacity;
}
