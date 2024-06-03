#include <iostream>
#include <vector>
using namespace std;

//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.

void moveZeroes(vector<int>& nums) {
    int n=nums.size(),j=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=0) nums[j++]=nums[i];
    }
    for(int i=j;i<n;i++) nums[i]=0;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "Modified vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}