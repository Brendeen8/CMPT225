#include <iostream>
#include <vector>

int main() {
    // 1. Basic Initialization and Access
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    
    // Access and modify elements
    int first = numbers[0];  // Access first element
    numbers[1] = 25;         // Modify second element
    
    // 2. Using push_back to Add Elements
    numbers.push_back(60);  // Add element to the end
    numbers.push_back(70);
    
    // 3. Iterating Over a Vector
    for (size_t i = 0; i < numbers.size(); i++) {
        int element = numbers[i];  // Access each element by index
    }

    // 4. Removing Elements from a Vector
    numbers.pop_back();  // Remove the last element
    
    // 5. Checking Size and Capacity of a Vector
    size_t size = numbers.size();      // Get the size of the vector
    size_t capacity = numbers.capacity();  // Get the capacity of the vector

    std::cout << "size :" << size << std::endl;
    std::cout << "capacity: " << capacity << std::endl;

    return 0;
}
