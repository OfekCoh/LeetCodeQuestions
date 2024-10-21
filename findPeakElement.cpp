// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

#include <iostream> 
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) 
{
    int mid, n=nums.size();
    int low=0, high=n-1;

    while(low<=high) {
        mid= (high+low)/2;
        int right= (mid+1==n)? INT_MIN : nums[mid+1] ; 
        int left= (mid==0)? INT_MIN : nums[mid-1] ;
        
        if( nums[mid]>right && nums[mid]>left ) return mid;
        if(right>left) low=mid+1;
        else high=mid-1;
    }
    return mid;
}

int main() 
{
    vector<int> vec={1,2,1,3,5,6,4};
    cout << findPeakElement(vec);
    return 0;
}