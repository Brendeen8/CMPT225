#include "Wordlist.h"
#include <iomanip>
using std::setprecision;
using std::fixed;
using std::max;
using std::cout;
using std::endl;

// Default Constructor
Wordlist::Wordlist() {
	root = nullptr;
}

// Insert Function
void Wordlist::insert(string word) {
	// Check if empty string
	if(word == "") {
		return;
	}
	root = insert(root, word);
}

// getCount Function
int Wordlist::getCount(string word) {
	return getCount(root, word);
}

// contains Function
bool Wordlist::contains(string word) {
	int val = getCount(word);
	if(val != 0) {
		return true;
	}
	return false;
}

// differentWords Function
int Wordlist::differentWords() {
	return countNodes(root);
}



// Prints useful statistics about the word list
void Wordlist::printStatistics() const
{
	/*
	cout << "Number of different words: " << differentWords() << endl;
	cout << "    Total number of words: " << totalWords() << endl;
	cout << "       Most frequent word: " << mostFrequent() << endl;
	cout << "     Number of singletons: " << singletons()
		<< setprecision(0) << fixed
		<< " (" << 100.0 * singletons() / differentWords() << "%)"
		<< endl;
		*/
}


// *** Helper Functions *** 

// Height Helper Function
int Wordlist::height(AVLTreeNode* node) {

	if(node != nullptr) {
		return node->height;
	}
	else {
		return -1;
	}

}

// Insert Helper Function
AVLTreeNode* Wordlist::insert(AVLTreeNode* node, string word) {

	if(node == nullptr) {
		node = new AVLTreeNode();
		node->word = word;
		node->left = nullptr;
		node->right = nullptr;
		node->count = 1;
	}

	// Insert Left if Smaller
	else if(word < node->word) {
		node->left = insert(node->left, word);
		node->left->parent = node;
	}

	// Insert Right if Larger
	else if(word > node->word) {
		node->right = insert(node->right, word);
		node->right->parent = node;
	}

	// Increment if duplicate
	else {
		node->count++;
		return node;
	}
	
	node->height = 1 + max(height(node->left), height(node->right));

	// Balance Tree (do later)

	return node;
}

// getCount Helper Function
int Wordlist::getCount(AVLTreeNode* node, string word) {
	// Return 0 if list is empty
	if(node == nullptr) {
		return 0;
	}
	// Traverse list in order
	else if(word < node->word) {
		return getCount(node->left, word);
	}
	else if(word > node->word) {
		return getCount(node->right, word);
	}
	else {
		return node->count;
	}
}

// differentWords Helper Function
int Wordlist::countNodes(AVLTreeNode* node) {
	if(node == nullptr) {
		return 0;
	}
	return 1 + countNodes(node->left) + countNodes(node->right);
}
