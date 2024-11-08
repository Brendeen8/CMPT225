#include "HeapT.h"
#include "largestm.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;

void testHeapT() {
    cout << "===== Testing HeapT =====\n\n";

    // Test 1: Constructor with invalid capacity
    try {
        cout << "Test 1: Constructor with invalid capacity...\n";
        HeapT<int> invalidHeap(0);
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << " (Capacity must be positive)\n";
    }

    // Test 2: Insert into a full heap
    cout << "\nTest 2: Insert into a full heap...\n";
    HeapT<int> heap(3);
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    try {
        heap.insert(40);
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << " (Heap is full)\n";
    }

    // Test 3: Peek and Remove on an empty heap
    cout << "\nTest 3: Peek and Remove on an empty heap...\n";
    HeapT<int> emptyHeap(5);
    try {
        emptyHeap.peek();
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << " (Heap is empty)\n";
    }
    try {
        emptyHeap.remove();
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << " (Heap is empty)\n";
    }

    // Test 4: Copy constructor
    cout << "\nTest 4: Copy constructor...\n";
    HeapT<int> originalHeap(5);
    originalHeap.insert(10);
    originalHeap.insert(5);
    originalHeap.insert(15);
    HeapT<int> copiedHeap(originalHeap);
    cout << "Original heap peek: " << originalHeap.peek() << ", Copied heap peek: " << copiedHeap.peek() << endl;

    // Test 5: Assignment operator
    cout << "\nTest 5: Assignment operator...\n";
    HeapT<int> assignedHeap(5);
    assignedHeap = originalHeap;
    cout << "Original heap peek: " << originalHeap.peek() << ", Assigned heap peek: " << assignedHeap.peek() << endl;

    // Test 6: Merge two heaps
    cout << "\nTest 6: Merge two heaps...\n";
    HeapT<int> heap1(5);
    heap1.insert(5);
    heap1.insert(10);
    HeapT<int> heap2(5);
    heap2.insert(3);
    heap2.insert(15);
    HeapT<int> mergedHeap = heap1.merge(heap2);
    cout << "Merged heap size: " << mergedHeap.size() << ", Merged heap peek: " << mergedHeap.peek() << endl;

    // Test 7: Size function
    cout << "\nTest 7: Size function...\n";
    cout << "Heap size: " << originalHeap.size() << " (Expected: 3)\n";
}

void testLargestm() {
    cout << "\n===== Testing largestm =====\n\n";

    // Test 1: Empty input vector
    cout << "Test 1: Empty input vector...\n";
    vector<int> emptyVec;
    vector<int> result = largestm(emptyVec, 5);
    cout << "Result size: " << result.size() << " (Expected: 0)\n";

    // Test 2: m = 0
    cout << "\nTest 2: m = 0...\n";
    vector<int> vec = {10, 20, 30};
    result = largestm(vec, 0);
    cout << "Result size: " << result.size() << " (Expected: 0)\n";

    // Test 3: m > vector size
    cout << "\nTest 3: m > vector size...\n";
    result = largestm(vec, 5);
    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << "(Expected: 30 20 10)\n";

    // Test 4: General case
    cout << "\nTest 4: General case...\n";
    vector<int> vec2 = {10, 5, 2, 8, 6, 4, 3, 9, 1};
    result = largestm(vec2, 4);
    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << "(Expected: 10 9 8 6)\n";

    // Test 5: m = 1
    cout << "\nTest 5: m = 1...\n";
    result = largestm(vec2, 1);
    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << "(Expected: 10)\n";
}

int main() {
    testHeapT();
    testLargestm();
    return 0;
}
