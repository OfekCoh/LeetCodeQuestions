#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// Given an integer array nums, return true if there exists a triple of 
// indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
// If no such indices exists, return false.


bool increasingTriplet(vector<int>& nums) {
    int a=INT_MAX,b=INT_MAX;
    for(auto x: nums){
        if(x<=a)    a=x;
        else if(x<=b)   b=x;
        else        return true;   
    }
    return false;
}

int main() {
    vector<int> input = {2,1,5,0,4,6};
    cout << increasingTriplet(input);
    return 0;
}