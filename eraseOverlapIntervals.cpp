// Given an array of intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int removed=0, end;
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b) 
        { 
            return a[1]<b[1];} );

    end=intervals[0][1];
    
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[i][0] < end) removed++;
        else end= intervals[i][1];       
    }
    return removed;
}

int main() {
    // Example input
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << "Input intervals:" << endl;
    for (auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Call the function
    int result = eraseOverlapIntervals(intervals);

    // Output the result
    cout << "Number of intervals removed: " << result << endl;

    return 0;
}
