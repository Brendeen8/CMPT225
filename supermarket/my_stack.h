#ifndef MY_STACK_H
#define MY_STACK_H

class Apple {
public:
    int id;
    bool is_sold = false;
};

class Node {
public:
    Apple* val;
    Node* next;
};

class MyStack {

public:
    MyStack();
    ~MyStack();

    MyStack(const MyStack& other);  // Copy constructor
    MyStack& operator=(const MyStack& other);  // Assignment operator

    void push(Apple* val);
    Apple* pop();
    int size();
    void print();

private:
    Node* top;
    int current_size;
};


#endif
