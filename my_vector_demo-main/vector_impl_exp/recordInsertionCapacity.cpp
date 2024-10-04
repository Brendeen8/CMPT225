#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main() {
    vector<long long> insertion_times;
    vector<size_t> capacities;

    ofstream file("insertion_times.csv");
    file << "Element Index,Insertion Time (ns),Capacity\n";

    vector<int> vec;
    size_t prev_capacity = vec.capacity();
    cout << "Initial capacity: " << prev_capacity << endl;

    for (int i = 0; i < 100; ++i) {
        auto start = high_resolution_clock::now();
        vec.push_back(i);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start).count();
        insertion_times.push_back(duration);
        capacities.push_back(vec.capacity());

        file << i << "," << duration << "," << vec.capacity() << "\n";
    }

    file.close();

    return 0;
}
