#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
// Any answer with a calculation error less than 10-5 will be accepted.

double findMaxAverage(vector<int>& nums, int k) {
    double max=0, temp=0;
    for(int i=0; i<k;i++)
    {
        temp+=nums[i];
    }
    max=temp/k;
    for(int i=k; i<nums.size();i++)
    {
        temp=temp+nums[i]-nums[i-k];
        if(max<temp/k) max=temp/k;
    }
    return max;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << "Maximum average of subarray of length " << k << " is: " << findMaxAverage(nums, k) << endl;
    return 0;
}