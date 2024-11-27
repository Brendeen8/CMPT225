#pragma once

template <class T>
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
  void insert(T val);

  // Remove Function
  T remove();

  // Peek Function
  T peek() const;

  // Merge Function
  HeapT merge(const HeapT& other) const;

  // Size Function
  int size() const;

private:
  int capacity;
  int currentSize;
  T* arr;

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

template <class T>
HeapT<T>::HeapT(int capacity) {

  if (capacity <= 0) {
    throw runtime_error("Capacity must be positive!");
  }
  this->capacity = capacity;
  currentSize = 0;
  arr = new T[capacity];
}

// Copy Constructor
template <class T>
HeapT<T>::HeapT(const HeapT& other) {
  copyFrom(other);
}

// Descructor
template <class T>
HeapT<T>::~HeapT() {
  delete[] arr;
}

// Assignment Operator
template <class T>
HeapT<T>& HeapT<T>::operator=(const HeapT& other) {
  
  // If not the same, deep copy
  if (this != &other) {
    delete[] arr;
    copyFrom(other);
  }
  return *this;
}

// Insert Function
template <class T>
void HeapT<T>::insert(T val) {

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
template <class T>
T HeapT<T>::remove() {
  
  // Check if array is empty
  if(currentSize == 0) {
    throw runtime_error("Heap is empty!");
  } 

  // Save root value
  T root = arr[0];

  // Set the root index as the last element
  arr[0] = arr[currentSize -1];
  currentSize--;

  // Bubble down heap
  heapifyDown(0);
  return root;
}

// Peek Function
template <class T>
T HeapT<T>::peek() const {
  if(currentSize == 0) {
    throw runtime_error("Heap is empty!");
  }
  return arr[0];
}

// Merge Function
template <class T>
HeapT<T> HeapT<T>::merge(const HeapT& other) const {

  // Create new heap with size of both heaps
  HeapT mergedHeap(capacity + other.capacity);

  // Copy both heaps into new heap
  copy(arr, arr + currentSize, mergedHeap.arr);
  copy(other.arr, other.arr + other.currentSize, mergedHeap.arr + currentSize);
  mergedHeap.currentSize = currentSize + other.currentSize;
 
  // Heapify new heap
  for(int i = (mergedHeap.currentSize - 2)/2; i >= 0; i--) {
    mergedHeap.heapifyDown(i);
  }

  return mergedHeap;
}

// Size Function
template <class T>
int HeapT<T>::size() const {

 return currentSize;
}

// Heapify Up Helper Function
template <class T>
void HeapT<T>::heapifyUp(int index) {
  
  // Loop until root
  while(index > 0) {
    int parent = (index - 1)/2;

    // Break if index value is greater than its parent
    if(arr[index] >= arr[parent]) {
      break;
    }
    // Switch index and it's parent
    swap(arr[index], arr[parent]);
    index = parent;
  }
}

// Heapify Down Function
template <class T>
void HeapT<T>::heapifyDown(int index) {

  // Loop until index gets to bottom
  while (2* index + 1 < currentSize) {
    int leftChild = 2 * index + 1;
    int rightChild = leftChild + 1;
    int smallerChild = leftChild;

    // Check which child is smaller
    if (rightChild < currentSize && arr[rightChild] < arr[leftChild]) {
      smallerChild = rightChild;
    }

    // Stop when the index value is less than both children
    if(arr[index] <= arr[smallerChild]) {
      break;
    }
    swap(arr[index], arr[smallerChild]);
    index = smallerChild;
  }
}

// Deep Copy Helper Function
template <class T>
void HeapT<T>::copyFrom(const HeapT& other) {
  // Create new memory
  this->arr = new T[capacity];

  // Copy
  copy(other.arr, other.arr + other.currentSize, this->arr);
 
  // Get all values of original heap
  this->capacity = other.capacity;
  this->currentSize = other.currentSize;

  
}

