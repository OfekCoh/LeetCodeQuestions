// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri 
// and column cj are equal.
// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    string temp;
    vector<string> row;
    vector<string> col;
    for (int i = 0; i < n; i++) {
        temp = "";
        for (int j = 0; j < n; j++) {
            temp += to_string(grid[i][j]) + " ";
        }
        row.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        temp = "";
        for (int j = 0; j < n; j++) {
            temp += to_string(grid[j][i]) + " ";
        }
        col.push_back(temp);
    }
    int sum = 0;
    for (const auto x : row) {
        for (const auto y : col) {
            if (x == y) sum++;
        }
    }
    return sum;
}

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}
    };

    // Call equalPairs and print the result
    int result = equalPairs(grid);
    cout << "Number of equal row and column pairs: " << result << endl;

    return 0;
}
