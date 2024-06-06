#include <iostream>
#include <vector>
using namespace std;

// Given a binary array nums and an integer k, 
// return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0;
    while(j<nums.size()){
        if(nums[j]==0){
            k--;
        }
        if(k<0){
            if(nums[i]==0){
                k++;
            }
            i++;
        }
        j++;
    }
    return j-i;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << "Longest subarray with at most " << k << " zeros is of length: " << longestOnes(nums, k) << endl;
    return 0;
}