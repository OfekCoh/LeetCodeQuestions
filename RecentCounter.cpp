// You have a RecentCounter class which counts the number of recent requests within a certain time frame.
// Implement the RecentCounter class:
// RecentCounter() Initializes the counter with zero recent requests.
// int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, 
// and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). 
// Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
// It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

#include <iostream>
#include <vector>
using namespace std;

class RecentCounter {
    vector<int> counter;
    int i;
public:
    RecentCounter() : i(0) {}

    int ping(int t) {
        counter.push_back(t);
        while(counter[i] < t - 3000) i++;
        return counter.size() - i;
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();

    // Test cases
    vector<int> testCases = {1, 100, 3001, 3002};

    for(int t : testCases) {
        int result = obj->ping(t);
        cout << "ping(" << t << ") -> " << result << endl;
    }

    // Clean up
    delete obj;

    return 0;
}