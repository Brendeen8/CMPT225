#pragma once
#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;

class SortedList
{
public:
	// Constructors and destructor
	SortedList(void);
	SortedList(int);
	SortedList(const SortedList & list);
	~SortedList(void);

	// Mutators
	void insert(string s);
	//void insert(string s, unsigned int & count);
	bool remove(string s);

	// Accessors
	string next();
	void reset();
	int size();

	// Overloaded assignment operator
	SortedList& operator=(const SortedList & list);

private:
	int current;
	int max;
	int pos;
	string* arr;
	void deepCopy(const SortedList & list);
};


