#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// You are given an integer array nums and an integer k.
// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
// Return the maximum number of operations you can perform on the array.


int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        int complement = k - nums[i];

        if (map.find(complement) != map.end()) {
            count++;
            if (map[complement] == 1) {
                map.erase(complement);
            } else {
                map[complement]--;
            }
        } else {
            map[nums[i]]++;
        }
    }

    return count;
}


int main() {
    std::vector<int> nums = {1, 2, 3, 4};  // Example input
    int k = 5;  // Example value for k

    int result = maxOperations(nums, k);
    std::cout << "The maximum number of operations is: " << result << std::endl;

    return 0;
}