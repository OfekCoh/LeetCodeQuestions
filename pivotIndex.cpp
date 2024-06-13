#include <iostream>
#include <vector>
using namespace std;

// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left 
// of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because 
// there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

int pivotIndex(vector<int>& nums) {
    vector<int> left;
    vector<int> right(nums.size(),0);

    for(int i=0;i<nums.size();i++)
    {
        if(i==0) left.push_back(0);
        else if(i==1) left.push_back(nums[0]);
        else left.push_back(nums[i-1]+left[i-1]);
    }

    for(int i=nums.size()-2;i>=0;i--)
    {
        right[i] = nums[i+1] + right[i+1];
    }

    if(right[0]==0) return 0;

    for(int i=1;i<nums.size();i++)
    {
        if(left[i]==right[i]) return i;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivot = pivotIndex(nums);
    cout << "Pivot index: " << pivot << endl;

    return 0;
}