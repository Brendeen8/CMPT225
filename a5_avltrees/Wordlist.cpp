#include "Wordlist.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <fstream>

using std::setprecision;
using std::fixed;
using std::max;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

// Default Constructor
Wordlist::Wordlist() {
	root = nullptr;
}

// File Constructor
Wordlist::Wordlist(string fname) {

	// Open File
	root = nullptr;
	ifstream myFile;
	myFile.open(fname);
	string next;

	// Insert text into wordlist
	while(myFile >> next) {
		insert(next);
	}
	myFile.close();
}

// Copy Constructor
Wordlist::Wordlist(const Wordlist& list) {

	// If list is empty, make copyied list empty
	if(list.getRoot() == nullptr) {
		root = nullptr;
	}

	// Copy the list
	else {
		root = copyTree(list.getRoot());
	}

	
}

// Overloaded Assignment Operator
Wordlist& Wordlist::operator=(const Wordlist& list) {

	// If they are the same, return 
	if (this == &list) {
		return *this;
	}
	// Ensure List is Empty
	destructor(root);

	// If list is empty, return empty list
	if(list.getRoot() == nullptr) {
		root = nullptr;
	}

	// Copy List
	else {
		root = copyTree(list.getRoot());
	}
	return *this;
}

// Destructor
Wordlist::~Wordlist() {
	
	// Delete the list
	destructor(root);
}

// Insert Function
void Wordlist::insert(string word) {
	
	// Check if empty string
	if(word == "") {
		return;
	}
	// Insert word recursively
	root = insert(root, word);
}

// Remove Function
bool Wordlist::remove(string word) {

	bool wasRemoved = false;

	// Remove word in list
	remove(root, word, wasRemoved);

	return wasRemoved;
}

// getCount Function
int Wordlist::getCount(string word) {
	return getCount(root, word);
}

// contains Function
bool Wordlist::contains(string word) {

	// Get the count of word
	int val = getCount(word);

	// If the it's in the list, return true
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

	// Initialize Variables
	string mostFrequentWord;
	int highestCount = 0;
	
	// Check if list is empty
	if(root == nullptr) {
		throw std::invalid_argument("Word list is empty!");
	}

	// Find most frequent word in list
	mostFrequent(root, mostFrequentWord, highestCount);
	
	// Convert into string
	string strAmount = std::to_string(highestCount);

	// Add word and its count into one string
	string wordAndAmount = mostFrequentWord + " " + strAmount;
	return wordAndAmount;
	
}

// Singletons Function
int Wordlist::singletons() const{

	int total = 0;
	
	// Get number of words with one count
	equalToOne(root, total);

	return total;
}

// printWords Function
void Wordlist::printWords() {
	int count = 0;
	printWords(root, count);
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


// Copy Constructor Helper Function
AVLTreeNode* Wordlist::copyTree(AVLTreeNode* node) {

	// Check if list is empty
	if(node == nullptr) {
		return nullptr;
	}

	// Copy Attributes
	AVLTreeNode* newNode = new AVLTreeNode();
	newNode->word = node->word;
	newNode->count = node->count;
	newNode->height = node->height;

	// Post order traversal
	newNode->left = copyTree(node->left);
	newNode->right = copyTree(node->right);

	return newNode;
}

// Destructor Helper Function
void Wordlist::destructor(AVLTreeNode* node) {

	// Check if list is empty
	if(node == nullptr) {
		return;
	}
	
	// Pre Order Traversal
	// Traverse Left Subtree
	destructor(node->left);
	
	// Traverse Right Subtree
	destructor(node->right);

	// Delete Node
	delete node;
	node = nullptr;
}

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
		node->height = 1;
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

 	// Calculate the balance factor
    int balanceFactor = height(node->left) - height(node->right);

    // Balance the tree based on the balance factor

    // Left-Left (LL) Case
    if (balanceFactor > 1 && word < node->left->word) {
        return rotateRight(node);
    }

    // Right-Right (RR) Case
    if (balanceFactor < -1 && word > node->right->word) {
        return rotateLeft(node);
    }

    // Left-Right (LR) Case
    if (balanceFactor > 1 && word > node->left->word) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-Left (RL) Case
    if (balanceFactor < -1 && word < node->right->word) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Return the (potentially updated) node pointer
    return node;

}

// Remove Helper Function
AVLTreeNode* Wordlist::remove(AVLTreeNode* node, string word, bool& wasRemoved) {

	if(node == nullptr) {
		wasRemoved = false;
		return nullptr;
	}
	if(word < node->word) {
		node->left = remove(node->left, word, wasRemoved);
	}
	else if(word > node->word) {
		node->right = remove(node->right, word, wasRemoved);
	}
	else {
		wasRemoved = true;

		if(node->left == nullptr && node->right == nullptr) {
			delete node;
			return nullptr;
		}

		if(node->left == nullptr) {
			AVLTreeNode* temp = node->right;
			delete node;
			return temp;
		}

		if(node->right == nullptr) {
			AVLTreeNode* temp = node->left;
			delete node;
			return temp;
		}

	AVLTreeNode* successor = findMin(node->right);
	node->word = successor->word;
	node->count = successor->count;
	node->right = remove(node->right, successor->word, wasRemoved);
	}

	node->height = 1 + max(height(node->left), height(node->right));
	return balance(node);
	
}

// Find Min (remove helper)
AVLTreeNode* Wordlist::findMin(AVLTreeNode* node) {
	while(node->left != nullptr) {
		node = node->left;
	}
	return node;
}

// Balance (remove and insert helper)
AVLTreeNode* Wordlist::balance(AVLTreeNode* node) {
	int balanceFactor = height(node->left) - height(node->right);

	if (balanceFactor > 1) {
   	 	if (height(node->left->left) >= height(node->left->right)) {
        	return rotateRight(node); // Left-Left (LL) Case
    } 
		else {
        	node->left = rotateLeft(node->left); // Left-Right (LR) Case
        	return rotateRight(node);
    	}
	}
	if (balanceFactor < -1) {
    	if (height(node->right->right) >= height(node->right->left)) {
     	   return rotateLeft(node); // Right-Right (RR) Case
   	} 
	else {
        node->right = rotateRight(node->right); // Right-Left (RL) Case
        return rotateLeft(node);
    }
}


	return node;
}

// Rotate Left Helper
AVLTreeNode* Wordlist::rotateLeft(AVLTreeNode* x) {
	AVLTreeNode* y = x->right;   // Y becomes the new root
    AVLTreeNode* B = y->left;   // Save Y's left subtree

    // Perform rotation
    y->left = x;
    x->right = B;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // Y is the new root of the subtree
}
// Rotate Right Helper
AVLTreeNode* Wordlist::rotateRight(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;    // X becomes the new root
    AVLTreeNode* B = x->right;  // Save X's right subtree

    // Perform rotation
    x->right = y;
    y->left = B;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x; // X is the new root of the subtree
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

// totalWords Helper Function (Counts the total amount of words)
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

// printWords Helper
void Wordlist::printWords(AVLTreeNode* node, int& currentNode) {

	if(node == nullptr) {
		return;
	}
	// Traverse Left Subtree
	printWords(node->left, currentNode);

	// Print Node and it's Attributes
	currentNode++;
	cout << currentNode << ". " << node->word << " " << node->count << endl;

	// Traverse Right Subtree
	printWords(node->right, currentNode);
}


