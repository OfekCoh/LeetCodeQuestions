// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, 
// she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::vector;

int minEatingSpeed(vector<int>& piles, int h)
{
    int low=1, high=*max_element(piles.begin(), piles.end()), mid;

    while(low<=high) {
        mid=(low+high)/2;
        long long sum=0;
        for(int num: piles) {
            sum+= num/mid;
            if(num%mid) sum++; // if we get a fraction need to add another whole hour 
        }
        if(sum>h) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main()
{
    int h=6;
    vector<int> piles={34};
    cout << minEatingSpeed(piles,h);
    return 0;
}