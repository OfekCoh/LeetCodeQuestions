// Given an array of integers temperatures represents the daily temperatures, return an array answer such that 
// answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;
using std::cout;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int> res(n,0);
    stack<int> stack;
    
    stack.push(0);
    
    for(int i=0;i<n;i++) {
        if(stack.empty()) stack.push(i);
        else {
            while(!stack.empty()) {
                int index=stack.top();
                if( temperatures[i] > temperatures[index]) {
                    res[index]=i-index;
                    stack.pop();
                }
                else break;
            }   
            stack.push(i);
        }
    }
    return res;
}

int main()
{
    vector<int> dailyTemps={73,74,75,71,69,72,76,73};
    vector<int> res=dailyTemperatures(dailyTemps);

    for(int x : res) cout << x << " ";

    return 0;
}