#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long accessAndMeasureTime(const vector<int>& vec, size_t index) {
    auto start = high_resolution_clock::now();
    volatile int element = vec[index];  // Access the element
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count();
}

int main() {
    // Initialize a vector with 100,000 elements
    vector<int> vec(100000, 0);

    // Measure the time for accessing different elements
    long long duration_first = accessAndMeasureTime(vec, 0);
    long long duration_second = accessAndMeasureTime(vec, 1);
    long long duration_last = accessAndMeasureTime(vec, vec.size() - 1);

    cout << "Time to access the first element: " << duration_first << " ns" << endl;
    cout << "Time to access the second element: " << duration_second << " ns" << endl;
    cout << "Time to access the last element: " << duration_last << " ns" << endl;

    return 0;
}
