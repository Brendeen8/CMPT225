#include "my_stack_array.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

int main()
{
  MyStack my_stack;
  std::string input;

  std::cout << "Comands:\n"
            << "push <value> : Push a value onto the stack\n"
            << "pop : Pop the top value from the stack\n"
            << "size: Get the size of the stack\n"
            << "print : Print the content of the stack\n"
            << "exit : Exit the program\n";

  while (true) {
    std::cout < "> ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string command;
  }
}
