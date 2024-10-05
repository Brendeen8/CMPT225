#include "StringList.h"
#include <stdexcept>
#include <iostream>
using std::out_of_range;
using std::cout;
using std::endl;
using std::to_string;
using std::stoi;

// Default constructor - makes an empty list of capacity 10
StringList::StringList()
{
	capacity = 10;
	n = 0;
	arr = new string[capacity];
  undoing = true;
}

// Copy constructor
StringList::StringList(const StringList& other)
{
	copyList(other);
}

// ***UNDOABLE
// Overloaded assignment operator
StringList& StringList::operator=(const StringList& other)
{
	if(&other != this)
	{
    if(undoing == true && n > 0) {
      string command = "COPY ";
      for (int i = 0; i < n; i++) {
        command += arr[i] + " ";
      }
      undoStack.push(command);
    }
    undoing = true;
		delete[] arr;
		copyList(other);
	}
	return *this;
}

// Destructor
StringList::~StringList()
{
	delete[] arr;
}

// ACCESSORS
// Returns the number of elements in the list
int StringList::size() const
{
	return n;
}

// Returns true if the list is empty, false otherwise
bool StringList::empty() const
{
	return n == 0;
}

// Returns the string at the given index
string StringList::get(int i) const
{
	checkBounds(i, "get");
	return arr[i];
}

// Returns the index of the first occurrence of the given string
int StringList::index(string s) const
{
	int i = 0;
	while (i < n && s != arr[i]) {
		i++;
	}
	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}

// Returns true iff the given string is in the list
bool StringList::contains(string str) const
{
	return !(index(str) == -1);
}

// Returns true if the two lists are equal, false otherwise.
// Does *not* consider any undo information when comparing two Stringlists. All
// that matters is that they have the same strings in the same order.
bool StringList::operator==(const StringList& sl) const
{
	if (size() != sl.size())
	{
		return false;
	}
	for (int i = 0; i < size(); i++)
	{
		if (get(i) != sl.get(i))
		{
			return false;
		}
	}
	return true;
}

// Returns true if the two lists are not equal, false otherwise
bool StringList::operator!=(const StringList& sl) const
{
	return !(*this == sl);
}

// Returns a string representation of the list.
string StringList::toString() const
{
	string result = "{";
	for (int i = 0; i < size(); i++)
	{
		if (i > 0) {
			result += ", ";
		}
		result += "\"" + get(i) + "\"";
	}
	return result + "}";
}


// MUTATORS

// ***UNDOABLE
// Sets the value at the given index
void StringList::set(int i, string str)
{
	checkBounds(i, "set");
  if(undoing == true) {
    undoStack.push("SET " + to_string(i) + " " + arr[i]);
  }
  undoing = true;
  arr[i] = str;

}

// ***UNDOABLE
// Inserts the given string *before* the given index
void StringList::insertBefore(int pos, string str)
{
	// Doesn't use checkBounds because it's okay to insert at the end
	if (pos < 0 || pos > size()) {
		throw out_of_range("StringList::insertBefore index out of bounds");
	}
	checkCapacity();
	for (int i = n; i > pos; i--) {
		arr[i] = arr[i-1];
	}
	arr[pos] = str;
	n++;
  if(undoing == true) {
    undoStack.push("REMOVE " + to_string(pos));
  }
  undoing = true;
  }

// ***UNDOABLE
// Inserts the given string at the front of the list
void StringList::insertFront(string str)
{
	checkCapacity();
  if(undoing == true) {
    undoStack.push("REMOVE " + to_string(0));
  }
  undoing = true;
  insertBefore(0, str);
}

// ***UNDOABLE
// Inserts the given string at the back of the list
void StringList::insertBack(string str)
{
	checkCapacity();
  undoing = true;
	insertBefore(n, str);
}

// ***UNDOABLE
// Removes the element at the given index and moves elements after it down
void StringList::remove(int pos)
{
	checkBounds(pos, "remove");
  if(undoing == true) {
    undoStack.push("INSERT " + to_string(pos) + " " + arr[pos]);
  }
  undoing = true;
  for (int i = pos; i < n; i++) {
	arr[i] = arr[i + 1];
	}
	n--;

}

// ***UNDOABLE
// Empties the list
void StringList::removeAll()
{
  if(undoing == true && n > 0) {
    string command = "COPY ";
    for (int i = 0; i < n; i++) {
      command += arr[i] + " "; // Add list element to command string
    }
    undoStack.push(command);
  }

	for (int i = 0; i < n; i++) {
		arr[i] = "";
	}
  undoing = true;
	n = 0;
}

// Undoes the last operation that modified the list
void StringList::undo()
{
  // Check if list is empty
  if (undoStack.isStackEmpty()) {
    cout << "Nothing to Undo" << endl;
    return;
  }
  undoing = false; // Set to false so undo doesn't undo itself in function
  string command = undoStack.pop(); // Get element from stack
  string action = command.substr(0, command.find(" ")); // Take the substring from 0 to space
                                                         
  if (action == "REMOVE") {
    int index = stoi(command.substr(7)); // Get index
    remove(index);
  }
  else if (action == "SET") {
    int index = stoi(command.substr(4)); // Get index
    string word = command.substr(command.find(" ", 4) + 1); // Get word
    set(index, word);
  }
  else if (action == "INSERT") {
    int index = stoi(command.substr(7)); // Get index
    string word = command.substr(command.find(" ", 7) + 1); // Get word
    insertBefore(index, word);
  }
  else if (action == "COPY") {
    removeAll(); // Clear List

    size_t pos = 5; // Set Position
    while (pos != string::npos) { // Loop until list empty
      size_t nextspace = command.find(" ", pos); // Find next position in command
      string element = command.substr(pos, nextspace - pos); // Get next element
      insertBack(element); 
      pos = (nextspace == string::npos) ? string::npos : nextspace + 1; // Go to nextspace 
    }
  }
  
}

// Prints the list
void StringList::print() const
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

// Helper function for checking index bounds.
void StringList::checkBounds(int i, string s) const
{
	if (i < 0 || i >= size()) {
		throw out_of_range("StringList::" + s + " index out of bounds");
	}
}

// POST: Doubles the capacity of the list if n == capacity
void StringList::checkCapacity()
{
	if (n == capacity) {
		capacity *= 2;
		string* temp = new string[capacity];
		
		for (int i = 0; i < n; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
}

// Helper function to copy the contents of another list
void StringList::copyList(const StringList& lst)
{
	capacity = lst.capacity;
	n = lst.n;
	arr = new string[capacity];

	for (int i = 0; i < n; i++) {
		arr[i] = lst.arr[i];
	}
}

StringList::Stack::Stack() 
{
  capacity = 4;
  topIndex = 0;
  myStack = new string[capacity];
}
StringList::Stack::~Stack()
{
  delete[] myStack;
}

// Push element from stack
void StringList::Stack::push(string str)
{
  checkStackCapacity();
  myStack[topIndex] = str;
  topIndex++;
}

// Pop element from stack
string StringList::Stack::pop()
{
  if(!myStack||isStackEmpty()) {
    throw std::out_of_range("Stack is empty, nothing to remove");
  }
  else {
    topIndex--;
    return myStack[topIndex];
  }
}

bool StringList::Stack::isStackEmpty() const
{
  return topIndex == 0;
}

void StringList::Stack::checkStackCapacity()
{
  // Double if full
  if(topIndex == capacity) {
    int newCapacity = capacity * 2;
    string* newStack = new string[newCapacity];

    // Copy elements
    for(int i = 0; i < topIndex; i++) {
      newStack[i] = myStack[i]; 
    } 
    delete[] myStack;
    myStack = newStack;
    capacity = newCapacity;
  }
}
