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
int Wordlist::differentWords() const{
	return countNodes(root);
}

// totalWords Function 
int Wordlist::totalWords() const{
	return countWords(root);
}

// mostFrequent Function
string Wordlist::mostFrequent() const{

	string mostFrequentWord;
	int highestCount = 0;
	mostFrequent(root, mostFrequentWord, highestCount);
	
	// convert contains into string
	string strAmount = std::to_string(highestCount);
	// add into one string
	string wordAndAmount = mostFrequentWord + " " + strAmount;
	return wordAndAmount;
}

int Wordlist::singletons() const{

	int total = 0;
	equalToOne(root, total);

	return total;
}



// Prints useful statistics about the word list
void Wordlist::printStatistics() const
{
	
	cout << "Number of different words: " << differentWords() << endl;
	cout << "Total number of words: " << totalWords() << endl;
	cout << "Most frequent word: " << mostFrequent() << endl;
	cout << "Number of singletons: " << singletons()
		<< setprecision(0) << fixed
		<< " (" << 100.0 * singletons() / differentWords() << "%)"
		<< endl;
		
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

// getCount Helper Function (How many times parameter is in list)
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

// differentWords Helper Function (Number of distinct words)
int Wordlist::countNodes(AVLTreeNode* node) const{
	if(node == nullptr) {
		return 0;
	}
	return 1 + countNodes(node->left) + countNodes(node->right);
}

int Wordlist::countWords(AVLTreeNode* node) const{
	if(node == nullptr) {
		return 0;
	}
	return node->count + countWords(node->left) + countWords(node->right);
}

// mostFrequent Helper Function 
void Wordlist::mostFrequent(AVLTreeNode* node, string& mostFrequentWord, int& highestCount) const{
	
	if(node == nullptr) {
		return;
	}

	mostFrequent(node->left, mostFrequentWord, highestCount);

	if(node->count > highestCount) {
		mostFrequentWord = node->word;
		highestCount = node->count;
	}
	
	mostFrequent(node->right, mostFrequentWord, highestCount); 
}

void Wordlist::equalToOne(AVLTreeNode* node, int& total) const{

	if(node == nullptr) {
		return;
	}

	equalToOne(node->left, total);

	if(node->count == 1) {
		total++;
	}

	equalToOne(node->right, total);
}


