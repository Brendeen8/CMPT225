#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand()

using namespace std;
using namespace std::chrono;

void checkMemoryAddresses(const std::vector<int>& vec) {
    std::cout << "Memory addresses of consecutive elements:\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element " << i << ": " << &vec[i] << "\n";
    }
}

int main() {
    std::vector<int> int_vec(5);

    checkMemoryAddresses(int_vec);
}
