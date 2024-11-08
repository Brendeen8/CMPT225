#pragma once

class HeapT {

public:   
 
  // Constructor
  HeapT(int capacity);

  // Copy Constructor
  HeapT(const HeapT& other);

  // Descructor
  ~HeapT();

  // Operator
  HeapT& operator=(const HeapT& other);

  // Insert Function
  void insert(int val);

  // Remove Function
  int remove();

  // Peek Function
  int peek() const;

  // Merge Function
  HeapT merge(const HeapT& other) const;

  // Size Function
  int size() const;

private:
  int capacity;
  int currentSize;
  int* arr;

  void heapifyUp(int index);
  void heapifyDown(int index);
  void copyFrom(const HeapT& other);
};

#include <iostream>
#include <stdexcept>
#include <algorithm>

using std::runtime_error;
using std::cout;
using std::endl;
using std::swap;

HeapT::HeapT(int capacity) {

  if (capacity <= 0) {
    throw runtime_error("Capacity must be positive");
  }
  this->capacity = capacity;
  currentSize = 0;
  arr = new int[capacity];
}

HeapT::HeapT(const HeapT& other) {
}

HeapT::~HeapT() {
  delete arr;
}
// Insert Function
void HeapT::insert(int val) {

  // Check if heap is full
  if(currentSize >= capacity) {
    throw runtime_error("Heap is Full!");
  }

  // Set last value to val
  arr[currentSize] = val;

  // Compare to parents
  heapifyUp(currentSize);
  currentSize++;
  
}

// Remove Function
int HeapT::remove() {
  return 1;
}

// Peek Function
int HeapT::peek() const {
  return arr[0];
}

// Merge Function
HeapT HeapT::merge(const HeapT& other) const {

  return HeapT(10);
}

// Size Function
int HeapT::size() const {

 return currentSize;
}

// Heapify Helper Function
void HeapT::heapifyUp(int index) {
  while(index > 0) {
    int parent = (index - 1)/2;
    if(arr[index] <= arr[parent]) {
      break;
    }
    swap(arr[index], arr[parent]);
    index = parent;
  }
}



