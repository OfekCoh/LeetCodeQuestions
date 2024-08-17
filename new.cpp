#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{    
    int n=nums1.size(), i=0, j=0;
    long long max=0, sum=0;
    vector<pair<int,int>> paired;
    
    // sort num2 and keep track of the original indexes
    for(i=0; i<n; i++) paired.push_back({nums2[i],i});
    sort(paired.begin(), paired.end());

    // now nums2 is nums1 with the sorted indexes of original nums2
    for(i=0;i<n;i++) nums2[i]=nums1[paired[i].second]; 

    // for each min in paired calc 
    for(j=0;j<k;j++) sum+=nums2[j];
    max=sum*paired[0].first;

    for(i=1;i<=n-k;i++)
    {
        sum-=nums2[i-1];
        sum+=nums2[j++];
        if(sum*paired[i].first > max) max= sum*paired[i].first;
    }

    return max;
}

int main()
{
    vector<int> nums1={};
    vector<int> nums2={};
    int k=3;

    cout<< maxScore(nums1, nums2, k);
    return 0;
}