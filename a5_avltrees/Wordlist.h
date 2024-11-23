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

	// Copy Constructor Helper 
	AVLTreeNode* copyTree(AVLTreeNode* node);

	// Destructor Helper
	void destructor(AVLTreeNode* node);

	// Insert Helper
	AVLTreeNode* insert(AVLTreeNode* node, string word);

	// Remove Helper
	AVLTreeNode* remove(AVLTreeNode* node, string word, bool& wasRemoved);

	// Find Min (remove helper)
	AVLTreeNode* findMin(AVLTreeNode*);

	// Balance Tree (helper for remove and insert)
	AVLTreeNode* balance(AVLTreeNode* node);

	// Rotate Left and Right Helper for balancing
	AVLTreeNode* rotateLeft(AVLTreeNode* x);
	AVLTreeNode* rotateRight(AVLTreeNode* y);

	// Height Helper
	int height(AVLTreeNode* node);

	// getCount Helper
	int getCount(AVLTreeNode* node, string word);

	// Counts distinct words
	int countNodes(AVLTreeNode* node) const;

	// Counts Total Words
	int countWords(AVLTreeNode* node) const;

	// Gets Most Frequent Word
	void mostFrequent(AVLTreeNode* node, string& mostFrequentWord, int& highestCount) const;

	// Gets how many words have exactly one count
	void equalToOne(AVLTreeNode* node, int& total) const;

	// Prints all words from least to greatest
	void printWords(AVLTreeNode* node, int& currentNode);

public:
	

	// Default Constructor
	Wordlist();

	// File Constructor
	Wordlist(string fname);

	// Copy Constructor
	Wordlist(const Wordlist& list);

	// Overloaded Assignment Operator
	Wordlist& operator=(const Wordlist& list);
	// Destructor
	~Wordlist();
	// Insert
	void insert(string word);
	// Remove
	bool remove(string word);
	// getCount
	int getCount(string word);
	// Contains
	bool contains(string word);
	// differentWords
	int differentWords() const;
	// totalWords
	int totalWords() const;
	// mostFrequent
	string mostFrequent() const;
	// Singletons
	int singletons() const;
	// Print Words
	void printWords();

	// Prints useful statistics about the word list
	void printStatistics() const;

	// Returns the root of the AVL tree
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
};