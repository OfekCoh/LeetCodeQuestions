// We are given an array asteroids of integers representing asteroids in a row.
// // For each asteroid, the absolute value represents its size, and the sign represents its direction 
// (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// // Find out the state of the asteroids after all collisions. If two asteroids meet, 
// the smaller one will explode. If both are the same size, both will explode. 
// Two asteroids moving in the same direction will never meet.


#include <iostream>
#include <vector>
using namespace std;

// Function declaration
vector<int> asteroidCollision(vector<int>& a);

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2}
    };
    
    // Loop through each test case and print the results
    for(auto& testCase : testCases) {
        cout << "Input: ";
        for(int ast : testCase) {
            cout << ast << " ";
        }
        cout << endl;
        
        vector<int> result = asteroidCollision(testCase);
        
        cout << "Output: ";
        for(int ast : result) {
            cout << ast << " ";
        }
        cout << endl << endl;
    }
    
    return 0;
}

// Function definition
vector<int> asteroidCollision(vector<int>& a) {
    int n = a.size(), right, left, i = 1;
    bool flag = 0;
    vector<int> res;
    res.push_back(a[0]);
    while (i < n) {
        if (flag == 0) res.push_back(a[i]);
        if (res.size() >= 2) {
            right = res.back();
            left = res[res.size() - 2];

            if (right < 0) {
                if (left >= 0) {
                    flag = 1;
                    if (left == (-right)) {
                        res.pop_back();
                        res.pop_back();
                    }
                    else if (left < (-right)) {
                        res.pop_back();
                        res.pop_back();
                        res.push_back(right);
                    }
                    else {
                        res.pop_back();
                    }
                }
                else flag = 0;
            }
            else flag = 0;
            if (res.size() < 2) flag = 0;
            if (!flag) i++;
        }
        else {
            flag = 0;
            i++;
        }
    }
    return res;
}
