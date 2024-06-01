#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// There are n kids with candies. 
// You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has,
// and an integer extraCandies, denoting the number of extra candies that you have.

// Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies,
// they will have the greatest number of candies among all the kids, or false otherwise.

// Note that multiple kids can have the greatest number of candies.

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result;
    auto max=*(max_element(candies.begin(), candies.end()));
    for(int i=0;i<candies.size();i++)
    {
        if(candies[i]+extraCandies >= max) result.push_back(true);
        else result.push_back(false); 
    }
    return result;
}

int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for (bool canHaveMaxCandies : result) {
        cout << (canHaveMaxCandies ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}