#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class AVLTreeNode {
public:
	
	AVLTreeNode* parent;
	AVLTreeNode* left;
	AVLTreeNode* right;
	string word;
	unsigned int count;
	unsigned int height;

};

// Wordlist class
class Wordlist
{
private:
	// Class attributes go here
	// Your class MUST have a root node named root (below)
	AVLTreeNode* root; // DO NOT REMOVE

public:
	

	// Default Constructor

	// File Constructor

	// Copy Constructor

	// Overloaded Assignment Operator

	// Destructor

	// Insert

	// Remove

	// getCount

	// Contains

	// differentWords

	// totalWords

	// mostFrequent

	// Singletons

	// Print Words

	// Prints useful statistics about the word list
	void printStatistics() const;

	// Returns the root of the AVL tree
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
};