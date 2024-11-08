#include "HeapT.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

int main() {
    try {
        cout << "Testing HeapT<int>...\n\n";

        // Test 1: Create a heap
        cout << "Creating a heap with capacity 5..." << endl;
        HeapT<int> heap(5);

        // Test 2: Insert elements
        cout << "Inserting elements: 10, 5, 20, 3, 7..." << endl;
        heap.insert(10);
        heap.insert(5);
        heap.insert(20);
        heap.insert(3);
        heap.insert(7);

        cout << "Heap after insertions (peek): " << heap.peek() << " (should be 3)" << endl;

        // Test 3: Test size function
        cout << "Current heap size: " << heap.size() << " (should be 5)" << endl;

        // Test 4: Remove root element
        cout << "Removing root element..." << endl;
        int removed = heap.remove();
        cout << "Removed: " << removed << " (should be 3)" << endl;
        cout << "New root after removal (peek): " << heap.peek() << " (should be 5)" << endl;

        // Test 5: Insert into a full heap (should throw exception)
        cout << "Attempting to insert into a full heap..." << endl;
        try {
            heap.insert(15);
        } catch (const runtime_error& e) {
            cout << "Caught exception: " << e.what() << endl;
        }

        // Test 6: Test merging two heaps
        cout << "\nTesting merge function..." << endl;
        HeapT<int> otherHeap(5);
        otherHeap.insert(8);
        otherHeap.insert(2);
        otherHeap.insert(12);

        cout << "Merging current heap with another heap (8, 2, 12)..." << endl;
        HeapT<int> mergedHeap = heap.merge(otherHeap);

        cout << "Merged heap size: " << mergedHeap.size() << " (should be 8)" << endl;
        cout << "Merged heap peek: " << mergedHeap.peek() << " (should be 2)" << endl;

        // Test 7: Test empty heap behavior
        cout << "\nTesting behavior with an empty heap..." << endl;
        HeapT<int> emptyHeap(5);
        try {
            emptyHeap.remove();
        } catch (const runtime_error& e) {
            cout << "Caught exception: " << e.what() << " (Heap is empty)" << endl;
        }

        // Test 8: Copy constructor
        cout << "\nTesting copy constructor..." << endl;
        HeapT<int> copyHeap(heap);
        cout << "Copy heap peek: " << copyHeap.peek() << " (should be same as original heap's peek)" << endl;

        // Test 9: Assignment operator
        cout << "\nTesting assignment operator..." << endl;
        HeapT<int> assignedHeap(5);
        assignedHeap = heap;
        cout << "Assigned heap peek: " << assignedHeap.peek() << " (should be same as original heap's peek)" << endl;

        cout << "\nAll tests completed successfully!" << endl;

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}