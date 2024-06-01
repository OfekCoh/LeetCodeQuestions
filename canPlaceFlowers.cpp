#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// You have a long flowerbed in which some of the plots are planted,
// and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
// return true if n new flowers can be planted in the flowerbed without violating 
// the no-adjacent-flowers rule and false otherwise.


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) {
        return true;
    }
    for (int i = 0; i < flowerbed.size(); i++) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
            flowerbed[i] = 1;
            n--;
            if (n == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;

    cout << "Test 1: Can place " << n1 << " flowers: " << (canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;
    cout << "Test 2: Can place " << n2 << " flowers: " << (canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;

    return 0;
}