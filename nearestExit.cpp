#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<vector<int>> q;  
    int m=maze.size(), n=maze[0].size();
    entrance.push_back(0); // add counter for steps
    q.push(entrance);

    while(!q.empty())
    {
        vector<int> temp= q.front();
        q.pop();
        int i=temp[0], j=temp[1], count=temp[2];
        maze[i][j]='+';

        if(i-1>=0) { // up
            if(maze[i-1][j]=='.') {
                if(i-1==0 || j==0 || j==n-1) return count+1;
                q.push(vector<int> {i-1,j,count+1});
            }
        }
        
        if(i+1<m) { // down 
            if(maze[i+1][j]=='.') {
                if(i+1 == m-1 || j==0 || j==n-1) return count+1;
                q.push(vector<int> {i+1,j,count+1});
            }
        }
        
        if(j-1>=0) { // left
            if(maze[i][j-1]=='.') {
                if(j-1 == 0 || i==0 || i==m-1) return count+1;
                q.push(vector<int> {i,j-1,count+1});
            }

        }
        
        if(j+1<n) { // right
            if(maze[i][j+1]=='.') {
                if(j+1 == n-1 || i==0 || i==m-1) return count+1;
                q.push(vector<int> {i,j+1,count+1});
            }
        }
    }
    return -1;
}

void printMaze(const vector<vector<char>>& maze, const vector<int>& entrance) {
    const string RED = "\033[31m";  // Red color
    const string RESET = "\033[0m"; // Reset color
    
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (i == entrance[0] && j == entrance[1]) {
                cout << RED << maze[i][j] << RESET << ' ';
            } else {
                cout << maze[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() 
{
    // Define the maze
    vector<vector<char>> maze = {
        {'.', '+', '+', '+', '+'},
        {'.', '+', '.', '.', '.'},
        {'.', '+', '.', '+', '.'},
        {'.', '.', '.', '+', '.'},
        {'+', '+', '+', '+', '.'}
    };
    vector<int> entrance = {1, 2}; // Example entrance position

    cout << "Initial Maze:\n\n";
    printMaze(maze, entrance);

    cout << "Result: " << nearestExit(maze, entrance) << '\n';

    return 0;
}
