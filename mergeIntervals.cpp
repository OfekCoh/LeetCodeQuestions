#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<pair<int,int>> temp;

    for(auto pair : intervals) temp.push_back({pair[0], pair[1]});
    sort(temp.begin(), temp.end());
    
    int first, second;

    for(int i=0;i<temp.size();i++) {
        first=temp[i].first;
        second=temp[i].second;
        vector<int> curr;
        
        while(i<temp.size()-1 && temp[i+1].first <= second) {
            second= max(second, temp[i+1].second);
            i++;
        }
        
        curr.push_back(first);
        curr.push_back(second);
        res.push_back(curr);
    }
    
    return res;
}