#include <iostream>
#include <string>
#include "my_stack.h"

using namespace std;

// Function to print the contents of the stacks
void printStacks(MyStack &stack1, MyStack &stack2) {
    cout << "===============Stack 1 (apples)===============" << endl;
    stack1.print();  // This function should now be marked as 'const'
    cout << "===============Stack 2 (apples)===============" << endl;
    stack2.print();
}

int main() {
    MyStack stack1;

    int apple_id_counter = 0;
    int num_apples = 3;
    for (int i = 0; i < num_apples; i++) {
        Apple* apple = new Apple();
        apple->id = apple_id_counter;
        apple_id_counter = apple_id_counter + 1;
        stack1.push(apple);
    }

    // Copy constructor
    MyStack stack2 = stack1;

    // Assignment operator overload
    // MyStack stack2;
    // stack2 = stack1;

    string command;
    cout << "Welcome to the supermarket stack manager! Type 'help' for available commands." << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "print") {
            printStacks(stack1, stack2);
        } 
        else if (command == "push stack1 apple") {
            Apple* apple = new Apple();
            apple->id = apple_id_counter;
            apple_id_counter = apple_id_counter + 1;
            stack1.push(apple);
            cout << "Apple added to stack 1." << endl;
        } 
        else if (command == "push stack2 apple") {
            Apple* apple = new Apple();
            apple->id = apple_id_counter;
            apple_id_counter = apple_id_counter + 1;
            stack2.push(apple);
            cout << "Apple added to stack 2." << endl;
        } 
        else if (command == "pop stack1") {
            Apple* apple = stack1.pop();
            apple->is_sold = true;
            cout << "Apple " << apple->id << " removed from stack 1 and sold." << endl;
            delete apple;
        } 
        else if (command == "pop stack2") {
            Apple* apple = stack2.pop();
            apple->is_sold = true;
            cout << "Apple " << apple->id << " removed from stack 2." << endl;
            delete apple;
        } 
        else if (command == "exit") {
            cout << "Exiting the program." << endl;
            break;
        } 
        else if (command == "help") {
            cout << "Available commands:" << endl;
            cout << "print            - Print the contents of both stacks" << endl;
            cout << "push stack1 apple - Push an apple to stack 1" << endl;
            cout << "push stack2 apple - Push an apple to stack 2" << endl;
            cout << "pop stack1       - Pop an apple from stack 1" << endl;
            cout << "pop stack2       - Pop an apple from stack 2" << endl;
            cout << "exit             - Exit the program" << endl;
        } 
        else {
            cout << "Unknown command. Type 'help' for available commands." << endl;
        }
    }

    return 0;
}
