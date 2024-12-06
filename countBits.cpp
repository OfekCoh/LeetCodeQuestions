// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    int low=0, high=1;   // this will save the jumps from 2^i to 2^i+1
    vector<int> ans(n+1);
    
    ans[0]=0;
    if(n==0) return ans;

    for(int i=1;i<=n;i++){
        
        if(i==high){
            ans[i]=1;
            low=high;
            high=high*2;
        }
        else ans[i]=(ans[i-low])+1;
    }
    
    return ans;
}


int main()
{
    int n=9;
    vector<int> arr=countBits(n);
    
    for(auto x : arr) cout << x;
    return 0;
}