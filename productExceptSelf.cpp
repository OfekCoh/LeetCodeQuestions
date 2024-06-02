#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// Given an integer array nums, return an array answer such that answer[i]
// is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n);
    vector<int> suf(n);
    vector<int> res(n);
    pre[0]=nums[0];
    suf[n-1]=nums[n-1];

    // Compute prefix product
    for (int i = 1; i < n; i++) {
        pre[i] = nums[i]*pre[i-1];
    }
    // Compute suffix product
    for (int i=n-2; i>=0; i--) {
        suf[i] = nums[i]*suf[i+1];
    }
    

    for(int i=0; i<n; i++)
    {
        if(i==0) res[i]=suf[1];
        else if(i==n-1) res[i]=pre[n-2];
        else res[i]= pre[i-1]*suf[i+1];
    }
    return res;
}

int main() {
    vector<int> input = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(input);

    cout << "Product except self: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}