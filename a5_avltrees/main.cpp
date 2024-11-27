#include "Wordlist.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Wordlist Test Driver (tiny_shakespeare.txt) ===" << endl;

    // Test 1: File Constructor and Print Statistics
    try {
        cout << "\nTest 1: File Constructor and Print Statistics" << endl;
        Wordlist wordlist("tiny_shakespeare.txt");
        wordlist.printStatistics(); // Should print statistics as specified in the prompt

        // Test 2: Print Words
        cout << "\nTest 2: Print Words" << endl;
        //wordlist.printWords();

        // Test 3: Check Contains and Get Count
        cout << "\nTest 3: Check Contains and Get Count" << endl;
        string testWord = "the";
        if (wordlist.contains(testWord)) {
            cout << "'" << testWord << "' is in the wordlist with count: " << wordlist.getCount(testWord) << endl;
        } else {
            cout << "'" << testWord << "' is not in the wordlist." << endl;
        }

        // Test 4: Remove a Word
        cout << "\nTest 4: Remove a Word" << endl;
        if (wordlist.remove(testWord)) {
            cout << "Removed '" << testWord << "' from the wordlist." << endl;
            wordlist.printStatistics(); // Check updated statistics
        } else {
            cout << "Could not remove '" << testWord << "' because it is not in the wordlist." << endl;
        }

        // Test 5: Most Frequent Word
        cout << "\nTest 5: Most Frequent Word" << endl;
        try {
            cout << "Most frequent word: " << wordlist.mostFrequent() << endl;
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "Error: Could not open the file tiny_shakespeare.txt. Make sure it exists in the folder." << endl;
    }

    cout << "\n=== End of Test Driver ===" << endl;
    return 0;
}
