#include "Stack.h"

Stack::Stack()
{
	capacity = 10;
	arr = new int[capacity];
	top = -1;
}

Stack::Stack(int val)
{
	capacity = val;
	arr = new int[capacity];
	top = -1;
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::push(int val)
{
	if (top == capacity) {
		throw out_of_range("stack is full");
	}

	arr[++top] = val;
}

int Stack::pop()
{
	if (top == - 1) {
		throw out_of_range("stack is empty");
	}

	int result = arr[top];
	top--;
	return result;
}

int Stack::size() const
{
	return top + 1;
}
