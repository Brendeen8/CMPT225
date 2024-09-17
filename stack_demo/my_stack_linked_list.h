#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H // tells compiler to only define header once
                          
class Node
{
  public:
    int val;
    Node* next;
};

class MyStackLinkedList
{
  public:
    MyStackLinkedList();
    ~MyStackLinkedList();

    void push(int val);
    int pop();
    int size();
    void print();

  private:
    Node* top;
    int current_size;
};





#endif
