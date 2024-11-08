//#pragma once

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
using std::copy;

HeapT::HeapT(int capacity) {

  if (capacity <= 0) {
    throw runtime_error("Capacity must be positive!");
  }
  this->capacity = capacity;
  currentSize = 0;
  arr = new int[capacity];
}

// Copy Constructor
HeapT::HeapT(const HeapT& other) {
  copyFrom(other);
}

// Descructor
HeapT::~HeapT() {
  delete[] arr;
}

// Assignment Operator
HeapT& HeapT::operator=(const HeapT& other) {
  
  // If not the same, deep copy
  if (this != &other) {
    delete[] arr;
    copyFrom(other);
  }
  return *this;
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
  
  // Check if array is empty
  if(currentSize == 0) {
    throw runtime_error("Heap is empty!");
  } 

  // Save root value
  int root = arr[0];

  // Set the root index as the last element
  arr[0] = arr[currentSize -1];
  currentSize--;

  // Bubble down heap
  heapifyDown(0);
  return root;
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
  
  // Loop until root
  while(index > 0) {
    int parent = (index - 1)/2;

    // Break if index value is less than its parent
    if(arr[index] <= arr[parent]) {
      break;
    }
    // Switch index and it's parent
    swap(arr[index], arr[parent]);
    index = parent;
  }
}

// Heapify Down Function
void HeapT::heapifyDown(int index) {

  // Loop until index gets to bottom
  while (2* index + 1 < currentSize) {
    int leftChild = 2 * index + 1;
    int rightChild = leftChild + 1;
    int largerChild = leftChild;

    // Check which child is greater
    if (rightChild < currentSize && arr[rightChild] > arr[leftChild]) {
      largerChild = rightChild;
    }

    // Stop when the index value is greater than both children
    if(arr[index] >= arr[largerChild]) {
      break;
    }
    swap(arr[index], arr[largerChild]);
    index = largerChild;
  }
}

// Deep Copy Helper Function
void HeapT::copyFrom(const HeapT& other) {

  // Get all values of original heap
  this->capacity = other.capacity;
  this->currentSize = other.currentSize;
  this->arr = new int[capacity];

  // Copy
  copy(other.arr, other.arr + other.currentSize, this->arr);
}

