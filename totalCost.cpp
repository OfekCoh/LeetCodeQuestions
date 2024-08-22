#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {
    long long sum=0;
    int n=costs.size(), i=candidates-1, j=n-candidates;
    while(n>=candidates) // we have enough workers to choose from
    {
        if(costs[i]<costs[j]) {
            sum+=costs[i];
            costs[i]=-1;
            i++;
            while( i<costs.size() && costs[i]==-1 ) i++;
        }
        else {
            sum+=costs[j];
            costs[j]=-1;
            j--;
            while( j>=0 && costs[j]==-1 ) j--;
        }
        n--;
        k--;
    }

    vector<int> minHeap;  // make min heap of the workers left and get the min k' times
    for(int x : costs) if(x!=-1) minHeap.push_back(x);

    make_heap(minHeap.begin(), minHeap.end(), greater<int>());
    
    while (k-- && !minHeap.empty())   // not enough workers, choose the minimum
    {
        pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
        sum+=minHeap.back();
        minHeap.pop_back();
    }
    return sum;
}
// n=9   i=3   j=5

int main() {
    
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    cout << "Total Cost: " << totalCost(costs, k, candidates) << endl;

    
    return 0;
}