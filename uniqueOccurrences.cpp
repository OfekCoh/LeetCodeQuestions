#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Given an array of integers arr, return true if the number of occurrences 
// of each value in the array is unique or false otherwise.

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> occurrenceCount;
    for (int num : arr) {
        occurrenceCount[num]++;
    }
    
    unordered_set<int> uniqueCounts;
    for (const auto& pair : occurrenceCount) {
        if (uniqueCounts.find(pair.second) != uniqueCounts.end()) {
            return false;
        }
        uniqueCounts.insert(pair.second);
    }
    
    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    bool result = uniqueOccurrences(arr);
    
    cout << "The array has unique occurrences: " << (result ? "true" : "false") << endl;

    return 0;
}
