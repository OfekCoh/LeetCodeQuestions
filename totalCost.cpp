// not the right answre for their question, but the right answer for candidates being only 2 options and not the min of 2*cadidates options.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates)
{
    long long sum=0;
    int n=costs.size(), i=candidates-1, j=n-candidates;
    while(n>=candidates) // we have enough workers to choose from
    {
        if(costs[i]<costs[j] || (costs[i]==costs[j] && i<j) ) {
            sum+=costs[i];
            costs[i]=-1;
            i++;
            while( i<costs.size() && costs[i]==-1 ) i++;
        }
        else if(costs[i]>costs[j] || (costs[i]==costs[j] && j<i) ){
            sum+=costs[j];
            costs[j]=-1;
            j--;
            while( j>=0 && costs[j]==-1 ) j--;
        }
        else {   // i==j
            sum+=costs[i];
            costs[i]=-1;
            i++;
            while( i<costs.size() && costs[i]==-1 ) i++;
            j--;
            while( j>=0 && costs[j]==-1 ) j--;
        }

        n--;
        k--;
        if(k==0) return sum;
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

int main()
{    
    vector<int> costs = {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    int k = 11;
    int candidates = 2;
    cout << "Total Cost: " << totalCost(costs, k, candidates) << endl;
    return 0;
}