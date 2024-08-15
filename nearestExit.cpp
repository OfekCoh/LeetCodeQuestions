// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, 
// where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. 
// Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<vector<int>> q;  
    int m=maze.size(), n=maze[0].size();
    entrance.push_back(0); // add counter for steps
    q.push(entrance);
    maze[entrance[0]][entrance[1]]='+';  // mark the entrance

    while(!q.empty())
    {
        vector<int> temp= q.front();
        q.pop();
        int i=temp[0], j=temp[1], count=temp[2];

        if(i-1>=0) { // up
            if(maze[i-1][j]=='.') {
                if(i-1==0 || j==0 || j==n-1) return count+1;
                q.push(vector<int> {i-1,j,count+1});
                maze[i-1][j]='+';     // we mark as visited so that others wont be able to mark them as well 
            }
        }
        
        if(i+1<m) { // down 
            if(maze[i+1][j]=='.') {
                if(i+1 == m-1 || j==0 || j==n-1) return count+1;
                q.push(vector<int> {i+1,j,count+1});
                maze[i+1][j]='+';
            }
        }
        
        if(j-1>=0) { // left
            if(maze[i][j-1]=='.') {
                if(j-1 == 0 || i==0 || i==m-1) return count+1;
                q.push(vector<int> {i,j-1,count+1});
                maze[i][j-1]='+';
            }

        }
        
        if(j+1<n) { // right
            if(maze[i][j+1]=='.') {
                if(j+1 == n-1 || i==0 || i==m-1) return count+1;
                q.push(vector<int> {i,j+1,count+1});
                maze[i][j+1]='+';
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
