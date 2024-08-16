#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> heap = {10, 4, 15, 20, 2};

    // Convert the vector into a min-heap using make_heap with greater<>
    make_heap(heap.begin(), heap.end(), greater<int>());

    // Displaying the min-heap
    cout << "Min-heap elements: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    // Adding a new element to the heap
    heap.push_back(1);
    push_heap(heap.begin(), heap.end(), greater<int>());

    // Displaying the heap after insertion
    cout << "After adding 1: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    // Removing the smallest element (min element) from the heap
    pop_heap(heap.begin(), heap.end(), greater<int>());
    heap.pop_back();

    // Displaying the heap after removal
    cout << "After removing the smallest element: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
