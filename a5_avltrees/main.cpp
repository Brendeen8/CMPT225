#include "Wordlist.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void) {
    cout << "Test" << endl;

    cout << "Inserting 'cat' into word list" << endl;

    Wordlist myList;
    
    myList.insert("cat");
    return 1;
}