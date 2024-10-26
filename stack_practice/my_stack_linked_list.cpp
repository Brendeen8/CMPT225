#include "my_stack_linked_list.h"
#include <iostream>
using std::cout;
using std::endl;

MyStackLinkedList::MyStackLinkedList() {
  top = nullptr;
  current_size = 0;
}

MyStackLinkedList::~MyStackLinkedList() {
  Node* temp = top;
  while(top != nullptr) {
    top = top->next;
    delete temp;
    temp = top;
  }
}

void MyStackLinkedList::push(int val) {
  Node* node = new Node();
  node->val = val;
  node->next = top;
  top = node;
  current_size = current_size + 1;
}

int MyStackLinkedList::pop() {
  int val = top->val;
  Node* temp = top;
  top = top->next;
  delete temp;
  current_size = current_size-1;
  return val;
}

int MyStackLinkedList::size() {
  return current_size;
}

void MyStackLinkedList::print() {
  Node* temp = top;
  while(temp != nullptr) {
    cout << temp->val << endl;
    temp = temp->next;
  }
}
