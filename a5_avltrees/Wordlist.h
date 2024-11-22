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

	// Insert Helper
	AVLTreeNode* insert(AVLTreeNode* node, string word);

	// Height Helper
	int height(AVLTreeNode* node);

	// getCount Helper
	int getCount(AVLTreeNode* node, string word);

	int countNodes(AVLTreeNode* node);

	int countWords(AVLTreeNode* node);



public:
	

	// Default Constructor
	Wordlist();

	// File Constructor
	Wordlist(string fname);

	// Copy Constructor

	// Overloaded Assignment Operator

	// Destructor
	//~Wordlist();
	// Insert
	void insert(string word);
	// Remove

	// getCount
	int getCount(string word);
	// Contains
	bool contains(string word);
	// differentWords
	int differentWords();
	// totalWords
	int totalWords();
	// mostFrequent

	// Singletons

	// Print Words

	// Prints useful statistics about the word list
	void printStatistics() const;

	// Returns the root of the AVL tree
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
};