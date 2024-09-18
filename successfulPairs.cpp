// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell 
// and potions[j] represents the strength of the jth potion.
// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n=spells.size();
    int m=potions.size();
    vector<int> res;

    sort(potions.begin(), potions.end());
    for(int i=0; i<n ; i++)
    {
        double minPotion = (double)success / spells[i];
        auto low= lower_bound(  potions.begin(), potions.end(), minPotion);
        res.push_back( m - (low - potions.begin()));
    }
    return res;
}


int main() {
    vector<int> spells = {10, 20, 30};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 100;

    vector<int> result = successfulPairs(spells, potions, success);

    for (int pairs : result) {
        cout << pairs << " ";
    }
    return 0;
}