#include "Wordlist.h"
#include <iomanip>
using std::setprecision;
using std::fixed;

Wordlist::Wordlist() {
	root = nullptr;
	size = 0;
}

void Wordlist::insert(string word) {
	if(word == "") {
		return;
	}

	if(root == nullptr) {
		root = new AVLTreeNode();
		root->val = word;
		root->left = nullptr;
		root->right = nullptr;
		root->count = 1;
		root->size++;
	}
	else {
		if(word < root->val) {
			root->left->val = word;
		}
	}

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
