// lab3.cpp : Defines the entry point for the console application.
//
#include "SortedList.h"
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>

using std::ifstream;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::vector;

void basicTest();
void profile(string fname);

vector<string> readFile(string infile);

int main()
{
	try {
		basicTest();
		//profile("animals_rand.txt");
		cout << endl;
		return 0;
	}
	catch (const runtime_error & re) {
		cout << re.what() << endl;
	}
}

// Opens a file and reads the contents into a SortedList
// The function does not remove non-alpha characters
// PARAM: fname is the name of the file to be opened
// PRE: the file contains words separated by white space
vector<string> readFile(string infile)
{
	ifstream ist(infile.c_str()); // open file
								  // Check if file opened correctly
	if (ist.fail()) {
		throw runtime_error("file not found");
	}

	// Read file into vector
	istream_iterator<string> start(ist), end;
	vector<string> result(start, end);

	return result;
}

// Test before profiling SortedList insert method
void basicTest()
{
	SortedList list(200);
	vector<string> vs = readFile("animals_rand.txt");

	for (string s : vs) {
		list.insert(s);
	}
	cout << "list contains " << list.size() << " values." << endl;
}

// Reaf file into list and print operations performed
// PARAM: fname is the name of the file to be opened
void profile(string fname)
{
	//unsigned int count = 0;
	//unsigned int total = 0;
	//SortedList list(200);

	//vector<string> vs = readFile("animals_sort.txt");

	//for (string s : vs) {
	//	list.insert(s, count);
	//	total += count;
	//	cout << "insert " << s << ", operations = " << count << endl;
	//}

	//cout << endl;
	//cout << "list contains " << list.size() << " values." << endl;
	//cout << "total operations performed = " << total << endl;
}




