// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <vector>
#include <algorithm>  // for sort
using namespace std;


int findKthLargest(vector<int>& nums, int k) {   // kth in sorted order
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int findKthLargest2(vector<int>& nums, int k) {  // kth by value 
    sort(nums.begin(), nums.end());
    auto last = unique(nums.begin(), nums.end());  // This function removes consecutive duplicate elements in the range [first, last) and returns an iterator to the new end of the range.
    nums.erase(last,nums.end());  // it doesnt change the size of the inital vector so we will delete the rest.
    // for(auto x:nums) cout << x;
    // cout<< endl;
    return nums[k];
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    int result = findKthLargest2(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
