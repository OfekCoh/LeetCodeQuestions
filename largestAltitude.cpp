#include <iostream>
#include <vector>
using namespace std;

// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. 
// The biker starts his trip on point 0 with altitude equal 0.
// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points 
// i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

int largestAltitude(vector<int>& gain) {
    int max=gain[0];
    for(int i=1;i<gain.size();i++)
    {
        gain[i]+=gain[i-1];
        if(gain[i]>max) max=gain[i];
    }
    return (max<0)? 0 : max;
}

int main() {
    // Sample data
    vector<int> gain = {-5, 1, 5, 0, -7};
    
    // Call the function and print the result
    int highestAltitude = largestAltitude(gain);
    cout << "The highest altitude is: " << highestAltitude << endl;

    return 0;
}