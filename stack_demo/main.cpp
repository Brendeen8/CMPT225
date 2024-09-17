
#include <iostream>
#include <sstream>
#include <chrono>
#include "my_stack_array.h"
#include "my_stack_linked_list.h"

void stack_operations_array();
void stack_operations_linked_list();
void compare_stacks(int num_items);

int main()
{
    std::string choice;
    
    std::cout << "Choose an option:\n"
              << "1: Use Array-based stack\n"
              << "2: Use Linked List-based stack\n"
              << "3: Compare both Array and Linked List for inserting and removing items\n";
    
    std::getline(std::cin, choice);
    
    if (choice == "3") {
        int num_items;
        std::cout << "Enter the number of items to test: ";
        std::cin >> num_items;
        compare_stacks(num_items);  // Pass the user-specified number of items
        return 0;
    } else if (choice == "1") {
        stack_operations_array();
    } else if (choice == "2") {
        stack_operations_linked_list();
    } else {
        std::cout << "Invalid choice! Exiting...\n";
        return 1;
    }

    return 0;
}

// Function to perform stack operations for the array-based stack
void stack_operations_array()
{
    MyStackArray my_stack;
    std::string input;
    
    std::cout << "Using Array-based stack.\n";
    std::cout << "Commands:\n"
              << "push <value> : Push a value onto the stack\n"
              << "pop : Pop the top value from the stack\n"
              << "size : Get the size of the stack\n"
              << "print : Print the content of the stack\n"
              << "exit : Exit the program\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::string command;
        ss >> command;

        if (command == "push") {
            int value;
            ss >> value;
            if (ss.fail()) {
                std::cout << "Invalid push command. Usage: push <int>\n";
            } else {
                my_stack.push(value);
            }
        } else if (command == "pop") {
            int val = my_stack.pop();
            std::cout << val << std::endl;
        } else if (command == "size") {
            std::cout << "Stack size: " << my_stack.size() << "\n";
        } else if (command == "print") {
            my_stack.print();
        } else if (command == "exit") {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }
}

// Function to perform stack operations for the linked list-based stack
void stack_operations_linked_list()
{
    MyStackLinkedList my_stack;
    std::string input;

    std::cout << "Using Linked List-based stack.\n";
    std::cout << "Commands:\n"
              << "push <value> : Push a value onto the stack\n"
              << "pop : Pop the top value from the stack\n"
              << "size : Get the size of the stack\n"
              << "print : Print the content of the stack\n"
              << "exit : Exit the program\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::string command;
        ss >> command;

        if (command == "push") {
            int value;
            ss >> value;
            if (ss.fail()) {
                std::cout << "Invalid push command. Usage: push <int>\n";
            } else {
                my_stack.push(value);
            }
        } else if (command == "pop") {
            int val = my_stack.pop();
            std::cout << val << std::endl;
        } else if (command == "size") {
            std::cout << "Stack size: " << my_stack.size() << "\n";
        } else if (command == "print") {
            my_stack.print();
        } else if (command == "exit") {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }
}

void compare_stacks(int num_items)
{
    MyStackArray array_stack(num_items);
    MyStackLinkedList linked_list_stack;

    std::cout << "Comparing array-based and linked list-based stacks for " << num_items << " items...\n";

    // Measure and compare insertions
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_items; ++i) {
        array_stack.push(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> array_duration = (end - start) * 1000;
    std::cout << "Array: Time taken to push " << num_items << " items: " << array_duration.count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_items; ++i) {
        linked_list_stack.push(i);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> linked_list_duration = (end - start) * 1000;
    std::cout << "Linked List: Time taken to push " << num_items << " items: " << linked_list_duration.count() << " ms\n";

    // Measure and compare removals
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_items; ++i) {
        array_stack.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    array_duration = (end - start) * 1000;
    std::cout << "Array: Time taken to pop " << num_items << " items: " << array_duration.count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_items; ++i) {
        linked_list_stack.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    linked_list_duration = (end - start) * 1000;
    std::cout << "Linked List: Time taken to pop " << num_items << " items: " << linked_list_duration.count() << " ms\n";
}
