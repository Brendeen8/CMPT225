// Test program for stack
//

#include <iostream>
#include <string>
#include "Stack.h"

using std::cout;
using std::endl;
using std::string;

//void intStackTest();
void doubleStackTTest();
void stringStackTTest();

int main()
{
    //intStackTest();
    cout << endl << endl;
    doubleStackTTest();
    cout << endl << endl;
    stringStackTTest();
}

// Test of Stack that stores ints
// TO DO - comment out body
// 
/*
void intStackTest()
{
    cout << "Int Stack Test" << endl;
    int stackCapacity = 4;
    Stack st(stackCapacity);
    
    // Push 1, 2, 3 and 4
    for (int i = 0; i < stackCapacity; i++) {
        st.push(i + 1);
    }
    cout << "Stack contains " << st.size() << " values" << endl;

    // Pop and print - prints 4, 3, 2, 1
    for (int i = 0; i < stackCapacity; i++) {
        cout << st.pop() << endl;
    }
}
*/
// Test of Stack template class that stores doubles
// TO DO - complete using intStackTest as model
void doubleStackTTest()
{
    cout << "Template Stack<double> Test" << endl;
    
    Stack<double> st;
    st.push(1.2);
    st.push(2.2);
    st.push(3.3);

    cout << "Stack contains " << st.size() << " values" << endl;

    // Pop and print - prints 3.3, 2.2, 1.1
    for (int i = 0; i < 3; i++) {
        cout << st.pop() << endl;
    }
}

// Test of Stack template class that stores strings
// TO DO - complete using doubleStackTTest as model
void stringStackTTest()
{
    cout << "Template Stack<string> Test" << endl;

    Stack<string> st;
    st.push("hello");
    st.push("world");

    cout << "Stack contains " <<  st.size() << " values" << endl;

    for (int i = 0; i < 2; i++) {
    cout << st.pop() << endl;
  }


}

