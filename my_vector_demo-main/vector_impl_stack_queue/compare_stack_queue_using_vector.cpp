#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>

using namespace std;
using namespace std::chrono;

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value) { 
        data.push_back(value); 
    }

    int pop() { 
        if (!data.empty()) {
            int topElement = data.back();  // Get the element to return
            data.pop_back();  // Remove the element
            return topElement;
        }
        return -1;
    }
};

class Queue {
private:
    std::vector<int> data;

public:
    void enqueue(int value) { 
        data.push_back(value); 
    }

    int dequeue() { 
        if (!data.empty()) {
            int frontElement = data.front();  // Get the element to return
            data.erase(data.begin());  // Remove the element from the front
            return frontElement;
        }
        return -1;
    }
};

int main() {
    Stack s;
    Queue q;

    const int num_elements = 100000;

    // Time Stack push and pop operations
    auto start_stack = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        s.push(i);
    }
    for (int i = 0; i < num_elements; ++i) {
        int poppedValue = s.pop();  // Pop and return the element
    }
    auto end_stack = high_resolution_clock::now();
    auto duration_stack = duration_cast<milliseconds>(end_stack - start_stack).count();
    cout << "Stack operations took: " << duration_stack << " ms" << endl;

    // Time Queue enqueue and dequeue operations
    auto start_queue = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        q.enqueue(i);
    }
    for (int i = 0; i < num_elements; ++i) {
        int dequeuedValue = q.dequeue();  // Dequeue and return the element
    }
    auto end_queue = high_resolution_clock::now();
    auto duration_queue = duration_cast<milliseconds>(end_queue - start_queue).count();
    cout << "Queue operations took: " << duration_queue << " ms" << endl;

    return 0;
}
