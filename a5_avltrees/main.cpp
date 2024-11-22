#include "Wordlist.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void) {
    cout << "Test" << endl;

    cout << "Inserting 'cat' into word list" << endl;

    Wordlist myList;
     // Insert words
    myList.insert("cat");
    myList.insert("dog");
    myList.insert("cat"); // Duplicate
    myList.insert("fish");
    myList.insert("tiger");


    // Get counts
    cout << "Count of 'cat': " << myList.getCount("cat") << endl; // Should print 2
    cout << "Count of 'dog': " << myList.getCount("dog") << endl; // Should print 1
    cout << "Count of 'bird': " << myList.getCount("bird") << endl; // Should print 0
    cout << "Count of 'fish': " << myList.getCount("fish") << endl; // Should print 2
    cout << "Count of 'tiger': " << myList.getCount("tiger") << endl; // Should print 2
   
    if(myList.contains("cat")) {
        cout << "List contains 'cat'" << endl;
    }
    else {
        cout << "List doesn't contain 'cat'" << endl;
    }

    if(myList.contains("bird")) {
        cout << "List contains 'bird'" << endl;
    }
    else {
        cout << "List doesn't contain 'bird'" << endl;
    }
    cout << "Number of distinct words: " << myList.differentWords() << endl;
    cout << "Total words: " << myList.totalWords() << endl;
    cout << "Most frequent word: " << myList.mostFrequent() << endl;
    cout << "Number of words with count of 1: " << myList.singletons() << endl;

    myList.printStatistics();
    return 1;

    
}