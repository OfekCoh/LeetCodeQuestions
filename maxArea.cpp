#include <iostream>
#include <string>
#include <vector>
using namespace std;

// You are given an integer array height of length n. There are n vertical lines drawn such that the two 
// endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.


int maxArea(vector<int>& h) {
    int n=h.size(), i=0, j=n-1,max=0,min,sum=0;
    while(i!=j)
    {
        min= (h[i] < h[j])? h[i]:h[j];
        sum= min*(j-i);
        if(max<sum) max=sum;
        if(min==h[i]) i++;
        else j--;
    }
    return max;
}  


int main() {
    // Test cases
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> heights2 = {1, 1};
    vector<int> heights3 = {4, 3, 2, 1, 4};
    vector<int> heights4 = {1, 2, 1};

    // Testing the function with the test cases
    cout << "Max area for heights1: " << maxArea(heights1) << endl;
    cout << "Max area for heights2: " << maxArea(heights2) << endl;
    cout << "Max area for heights3: " << maxArea(heights3) << endl;
    cout << "Max area for heights4: " << maxArea(heights4) << endl;

    return 0;
}