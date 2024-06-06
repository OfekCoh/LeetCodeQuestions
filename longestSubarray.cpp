#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
// Return 0 if there is no such subarray.

int longestSubarray(vector<int>& nums) {
    int temp=0, i, max=0;
    if(nums.size()==1) return 0;
    for(i=0;i<nums.size();i++)
    {
        while(i<nums.size() && nums[i]==1 )
        {
            temp++;
            nums[i++]=temp;
        }

        if( i<nums.size() && nums[i]==0) temp=0;
    }
    for(i=nums.size()-1;i>=0;i--)
    {
        if(nums[i]!=0) temp=nums[i];
        if(temp>max) max=temp;
        while(i>=0 && nums[i]!=0){
            nums[i--]=temp;
        }
    }
    for(i=0;i<nums.size()-2;i++){
        if(nums[i]!=0 && nums[i+1]==0 && nums[i+2]!=0){
            temp=nums[i]+nums[i+2];
            if(temp>max) max=temp;
        }
    }
    if(max==nums.size()) return max-1;
    return max;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << "Longest subarray of 1s after deleting one element: " << longestSubarray(nums) << endl;
    return 0;
}