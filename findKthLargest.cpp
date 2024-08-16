// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <vector>
#include <algorithm>  // Include this for std::sort
using namespace std;


int findKthLargest(std::vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    int result = findKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
