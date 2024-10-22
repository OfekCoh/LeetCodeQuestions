#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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