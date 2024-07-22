// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, 
// then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int res = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (isConnected[node][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            res++;
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> isConnected[i][j];
        }
    }

    int numProvinces = findCircleNum(isConnected);
    cout << "The number of provinces is: " << numProvinces << endl;

    return 0;
}
