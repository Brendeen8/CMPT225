#include "my_stack.h"
#include <iostream>
using std::cout;
using std::endl;

MyStack::MyStack()
{
    // Let the link list grows backwaord -> easier to delete the list
    top = nullptr;
    current_size = 0;
}

MyStack::MyStack(const MyStack& other) {
    top = nullptr;
    current_size = 0;
    if (other.top != nullptr) {
        Node* temp = other.top;
        Node* prev = nullptr;
        
        // Copy the first node
        top = new Node();
        Apple* copy_apple = new Apple();
        copy_apple-> id = temp->val->id;
        top->val = copy_apple ;  // Fix here: deep copy the Apple object
        prev = top;
        temp = temp->next;
        current_size++;

        // Copy the rest of the nodes
        while (temp != nullptr) {
            Node* newNode = new Node();
            Apple* copy_apple = new Apple();
            copy_apple-> id = temp->val->id;
            newNode->val = copy_apple ;  // Fix here: deep copy the Apple object
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
            current_size++;
        }
        prev->next = nullptr;
    }
}

MyStack& MyStack::operator=(const MyStack& other) {
    if (this == &other) {
        return *this;
    }

    // Clear current stack
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp->val;
        delete temp;
    }
    current_size = 0;

    // Deep copy from the other stack
    if (other.top != nullptr) {
        Node* temp = other.top;
        Node* prev = nullptr;
        
        // Copy the first node
        top = new Node();
        top->val = new Apple(*(temp->val));
        prev = top;
        temp = temp->next;
        current_size++;

        // Copy the rest of the nodes
        while (temp != nullptr) {
            Node* newNode = new Node();
            newNode->val = new Apple(*(temp->val));
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
            current_size++;
        }
        prev->next = nullptr;
    }
    
    return *this;
}

MyStack::~MyStack()
{
    Node* temp = top;
    while (top != nullptr) {
        top = top->next;
        delete temp->val;
        delete temp;
        temp = top;
    }
}

void MyStack::push(Apple* val)
{
    Node* node = new Node();
    node->val = val;
    node->next = top;
    top = node;
    current_size = current_size + 1;
}

Apple* MyStack::pop()
{
    Apple* val = top->val;
    Node* temp = top;
    top = top->next;
    delete temp;
    current_size = current_size - 1;
    return val;
}

int MyStack::size()
{
    return current_size;
}

void MyStack::print()
{
    Node* temp = top;
    while(temp != nullptr) {
        if (temp->val->is_sold == false) {
            cout << "Apple " << temp->val->id << " is in stock" << endl;
        } else {
            cout << "Apple " << temp->val->id << " is sold" << endl;
        }
        temp = temp->next;
    }
}
