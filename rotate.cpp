#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n= matrix[0].size();

    // transpose
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    //swap columns
    for(int i=0;i<n;i++) {
        int k=0,j=n-1;
        while(k<j) {
            int temp=matrix[i][k];
            matrix[i][k]=matrix[i][j];
            matrix[i][j]=temp;
            j--;
            k++;
        }
    }
}

void print_matrix(vector<vector<int>> matrix) {
    for(auto row : matrix) {
        for (auto curr : row) {
            cout << curr << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix= { {1,2}, {3,4}};
    print_matrix(matrix);   
    rotate(matrix);
    print_matrix(matrix);   
    return 0;
}