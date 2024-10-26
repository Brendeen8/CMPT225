#include <iostream> // for cout
#include "ArrayClass.h"

using namespace std;

// Function Prototype
void arrayClassTest();
void exceptionTest();

// Main function that is called when the program is executed
int main() {
	//arrayClassTest();
	exceptionTest();
  
	return 0;
}

void arrayClassTest() {
	ArrayClass ac;
	ac.insert(1);
	ac.insert(2);

	cout << "ac.size()  = " << ac.size() << endl;

	// Insert the values 1 to 7 in ac1
	for (int i = 3; i <= 40; ++i) {
		ac.insert(i);
	}

	cout << "ac.size()  = " << ac.size() << endl;
	cout << "ac.sum() = " << ac.sum() << endl;
}

void exceptionTest() {
	ArrayClass ac;

	// Insert 1 to 10 integers in ac
	int n = 10;
	for (int i = 0; i < n; ++i) {
		ac.insert(i + 1);
	}

	// Get and set values (which may throw errors)
	try {
    for(int i = 0; i <= ac.size() -1 ; i++) {
      ac.set(i,-1);
      cout << ac.get(i) << endl;
    }
		// "Accidentally" access the 11th element
		for (int i = 0; i <= ac.size(); ++i) {
			cout << ac.get(i) << endl;
		}

	}
	catch (std::out_of_range oor) {
		cout << oor.what() << endl;
	}
}



