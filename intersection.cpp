#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.

vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> hist(1001,0);
    int n = nums.size();
    
    for(auto vec: nums) {
        for(auto x : vec) {
            hist[x]++;
        }
    }
    vector<int> res;
    for(int i=1; i<hist.size();i++) {
        if(hist[i]==n) res.push_back(i);
    }

    return res;