#ifndef STACK_H
#define STACK_H

class MyStack {
  public:
    MyStack();
    ~MyStack(); //destructor

    void push(int val);
  int pop(int);
    int size();
    void print();


  private:
    int capacity; //max number of elements
    int* container; // pointer of array used to store and move elements
    int top; //index of top element


};





#endif
