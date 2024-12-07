#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<vector<int>> groupSort(vector<int> arr) {
    unordered_map<int,int> map;  // map of(value,frequency)
    int n=arr.size();
    vector<vector<int>> res;
    
    // calc map of(value,frequency)
    for(int i=0;i<n;i++) {
        if( map.find(arr[i])==map.end() ) map[arr[i]]=1; // first occurance of the value
        else map[arr[i]]++; // not the first occ so add 1 to frequency
    }
    
    // create 2D vector res
    for(auto x : map) {
        vector<int> temp(2);
        temp[0]=x.first;
        temp[1]=x.second;
        res.push_back(temp);
    }
    
    // sort the vector res
    sort(res.begin(),res.end(),[](const vector<int>& a, const vector<int>& b) {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]>b[1];
    });
    
    return res; 
}

int main() {
    vector<int> arr={2,2,4,5,6,8,9,6,3,2,4,5,2,};
    vector<vector<int>> res=groupSort(arr);

    for(int i=0;i<res.size();i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}