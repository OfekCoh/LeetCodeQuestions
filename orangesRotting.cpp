// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
    queue<vector<int>> rotten;  // queue for all rotten cells
    int max_count=0, n=grid.size(), m=grid[0].size(), fresh=0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]==2) rotten.push({i,j,0});  // push rotten cell to queue
            if(grid[i][j]==1) fresh++;
        }                          
    }

    while(!rotten.empty()) {
        vector<int> x = rotten.front();
        rotten.pop();
        int i=x[0], j=x[1], count=x[2];
        if(count > max_count) max_count=count;

        if(i-1>=0) { // up
            if(grid[i-1][j]==1) {
                rotten.push({i-1,j,count+1});
                grid[i-1][j]=2;
                fresh--;
            }
        }
        
        if(i+1<n) { // down 
            if(grid[i+1][j]==1) {
                rotten.push({i+1,j,count+1});
                grid[i+1][j]=2;
                fresh--;
            }
        }
        
        if(j-1>=0) { // left
            if(grid[i][j-1]==1) {
                rotten.push({i,j-1,count+1});
                grid[i][j-1]=2;
                fresh--;
            }

        }
        
        if(j+1<m) { // right
            if(grid[i][j+1]==1) {
                rotten.push({i,j+1,count+1});
                grid[i][j+1]=2;
                fresh--;
            }
        }
    }
    if(fresh) return -1;
    return max_count;   
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    if (result == -1) {
        cout << "All oranges cannot rot." << endl;
    } else {
        cout << "Minimum time required for all oranges to rot is: " << result << " minutes." << endl;
    }

    return 0;
}
