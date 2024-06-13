#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> hash1;
    unordered_set<int> hash2;
    for(int i=0;i<nums1.size();i++){
        hash1.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
        hash2.insert(nums2[i]);
    }
    vector<vector<int>> answer;
    vector<int> first;
    vector<int> second;

    for(auto it = hash1.begin(); it != hash1.end(); ++it){
        if (hash2.find(*it) == hash2.end()) {
            second.push_back(*it);
        }
    }
    for(auto it = hash2.begin(); it != hash2.end(); ++it){
        if (hash1.find(*it) == hash1.end()) {
            first.push_back(*it);
        }
    }
    answer.push_back(second);
    answer.push_back(first);
    return answer;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = findDifference(nums1, nums2);

    cout << "Elements unique to nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Elements unique to nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}