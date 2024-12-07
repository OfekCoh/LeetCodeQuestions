#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) 
{
    int n=nums.size(),temp=nums[0];
    for(int i=0;i<n-1;i++){
        temp= temp^nums[i+1];
    }
    return temp;
}

int main()
{
    vector<int> nums={2,2,6,5,6};
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}