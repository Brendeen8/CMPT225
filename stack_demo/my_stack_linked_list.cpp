#include "my_stack_linked_list.h"
#include <iostream>
using std::cout;
using std::endl;

MyStackLinkedList::MyStackLinkedList() // define private variables
{
  top = nullptr;
  current_size = 0;
}

MyStackLinkedList::~MyStackLinkedList() // delete list
{
  Node* temp = top;
  while(top != nullptr) { // goes until end of list
    top = top->next;
    delete temp;
    temp = top;
  }
}

void MyStackLinkedList::push(int val) // insert at front of list
{
  Node* node = new Node();
  node->val = val; // make the node's value the given value
  node->next = top; // set the 2nd element as top
  top = node; // make the 1st element node
  current_size += 1;
}

int MyStackLinkedList::pop() // remove and return front
{
  int val = top->val; // get front value
  Node* temp = top; // make a temperary node the top
  top = top->next; // set the top as the 2nd element
  delete temp; // delete the top
  current_size -= 1;
  return val;
}

int MyStackLinkedList::size()
{
  return current_size; // return private element
}

void MyStackLinkedList::print()
{
  Node* temp = top;
  while(temp != nullptr) {
    cout << temp->val << endl;
    temp = temp->next;
  }
}
