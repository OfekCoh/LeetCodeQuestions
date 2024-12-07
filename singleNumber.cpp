// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) 
{
    int n=nums.size(),temp=nums[0];
    for(int i=0;i<n-1;i++){
        temp= temp^nums[i+1];  // using XOR between all elements. A^A=0, 0^B=B.
    }
    return temp;
}

int main()
{
    vector<int> nums={2,2,6,5,6};
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}