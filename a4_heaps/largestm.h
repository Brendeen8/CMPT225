#pragma once

#include "HeapT.h"
#include <vector>
#include <stdexcept>

using std::vector;

template <typename T>
vector<T> largestm(const vector<T>& values, int m) {
    
    // Create result vector
    vector<T> result;

    // Return if m is invalid or vector empty
    if(m <= 0 || values.empty()) {
        return result;
    }

    // Create a heap to sort values
    HeapT<T> heap(m);

    // Insert values into heap
    for(const T& value : values) {

        // If heap is not full, add
        if (heap.size() < m) {
            heap.insert(value);
        }
        // If heap is full and value is greater than smallest element, add
        else if(value > heap.peek()) {
            heap.remove();
            heap.insert(value);
        }
    }
    // Make vector same size as heap
    result.resize(heap.size());

    int index = heap.size()-1;
    
    // Add elements from heap into vector
    while (heap.size() > 0) {
        result[index--] = heap.remove();
    }
    return result;
}
