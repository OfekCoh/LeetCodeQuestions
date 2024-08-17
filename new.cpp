#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{    
    int n=nums1.size();
    long long max=0, sum=0,temp=0;
    vector<pair<int,int>> paired;
    
    // sort num2 and keep track of the original indexes
    for(int i=0; i<n; i++) paired.push_back({nums2[i],i});
    sort(paired.begin(), paired.end());

    // Create vector B for nums1 values sorted like nums2
    vector<int> B(n);
    for(int i=0;i<n;i++) B[i]=nums1[paired[i].second]; 

    // Create min-heap of the first k elements from B
    vector<int> minHeap(B.end() - k, B.end());
    make_heap(minHeap.begin(), minHeap.end(), greater<int>());
    
    for(int i=0;i<k;i++) sum+=minHeap[i];
    max=sum*paired[n-k].first;  

    // check all elements with the new min paired[i].first
    for(int i=n-k-1;i>=0;i--) {
        if(B[i]>minHeap[0]){   // A[0]=A.top()
            sum+=B[i]-minHeap[0];
            pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
            minHeap.pop_back();
            minHeap.push_back(B[i]);
            push_heap(minHeap.begin(),minHeap.end(),greater<int>());
        }
        temp=sum*paired[i].first;
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

// k=3
// n=4

// nums1 = 2 1 14 12   
// nums2 = 11 7 13 6 

// paired=  (6,3), (7,1), (11,0), (13,2)

// minHeap = 1 2 14         
// B = 12 {1 2 14}

// sum= 0
// max= 0
