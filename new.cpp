#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{    
    int n=nums1.size(), i=0, temp=0;
    long long max=0, sum=0;
    vector<pair<int,int>> paired;
    
    // sort num2 and keep track of the original indexes
    for(i=0; i<n; i++) paired.push_back({nums2[i],i});
    sort(paired.begin(), paired.end());

    // now nums2 is nums1 with the sorted indexes of original nums2
    for(i=0;i<n;i++) nums2[i]=nums1[paired[i].second]; 

    // create min heap of size k
    vector<int> A;
    vector<int> B;

    for(i=n-1;i>=0;i--){
        A.push_back(nums2[i]);
        B.push_back(paired[i].first);
    }

    // make the heap
    make_heap(A.begin(), A.begin()+k, greater<int>());
    for(i=0;i<k;i++) sum+=A[i];
    max=sum*B[k-1];

    // check all elements with the new min B[i]
    for(i=k;i<n;i++) {
        if(A[i]>A[0]){   // A[0]=A.top()
            sum-=A[0];
            A[0]=A[i];
            sum+=A[i];
            push_heap(A.begin(),A.begin()+k,greater<int>());
        }
        temp=sum*B[i];
        if(temp>max) max=temp;
    }   

    return max;
}

int main()
{
    vector<int> nums1={2,1,14,12};
    vector<int> nums2={11,7,13,6};
    int k=3;

    cout<< maxScore(nums1, nums2, k);
    return 0;
}

