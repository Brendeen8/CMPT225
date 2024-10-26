#include <iostream>
#include "my_stack_array.h"
#include "my_stack_linked_list.h"
using std::cout;
using std::endl;

int main(void) {

  MyStackArray myStack(10);
  myStack.push(1);
  for(int i = 0 ; i < 20; i++) {
    myStack.push(i);
  }
  myStack.print();
  int size = myStack.size();
  cout << "The size is: " << size << endl;

  MyStackLinkedList myStackList;

  myStackList.push(1);
  myStackList.print();
  return 1;
}
