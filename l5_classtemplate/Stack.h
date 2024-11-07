#pragma once
#include<stdexcept>

using std::out_of_range;
template <class T>
class Stack
{
public:
	// Constructors
	// Default constructor
	// POST: creates array of size 10, sets capacity to 10, top to -1
	Stack();

	// PARAM: n - size of array to be created
	// POST: creates array of size n, sets capacity to 10, top to -1
	Stack(int n);

	// POST: Deallocates dynamic memory associated with arr
	~Stack();

	// Mutators
	// ERROR: throws out_of_range if full
	// PARAM: val - value to be inserted in stack
	// POST: inserts value at top of stack
	void push(T val);

	// ERROR: throws out_of_range if empty
	// POST: removes and returns value at top of stack
	T pop();

	// Accessor
	// POST: returns the number of values in the Stack
	int size() const;

private:
	T* arr;
	int capacity;
	int top;
};

template <class T>
Stack<T>::Stack()
{
	capacity = 10;
	arr = new T[capacity];
	top = -1;
}

template <class T>
Stack<T>::Stack(int val)
{
	capacity = val;
	arr = new T[capacity];
	top = -1;
}

template <class T>
Stack<T>::~Stack()
{
	delete[] arr;
}

template <class T>
void Stack<T>::push(T val)
{
	if (top == capacity) {
		throw out_of_range("stack is full");
	}

	arr[++top] = val;
}

template <class T>
T Stack<T>::pop()
{
	if (top == - 1) {
		throw out_of_range("stack is empty");
	}

	T result = arr[top];
	top--;
	return result;
}

template <class T>
int Stack<T>::size() const
{
	return top + 1;
}
