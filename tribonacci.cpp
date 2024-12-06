// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

#include <iostream>
#include <vector>
using namespace std;

int tribonacci(int n) {
    vector<int> threeLast = {0, 1, 1};
    int sum;

    if (n < 3) return threeLast[n];

    for (int i = 3; i <= n; i++) {
        sum = threeLast[0] + threeLast[1] + threeLast[2];
        threeLast[0] = threeLast[1];
        threeLast[1] = threeLast[2];
        threeLast[2] = sum;
    }

    return threeLast[2];
}

int main() {
    int n=25;

    int result = tribonacci(n);
    cout << "Tribonacci(" << n << ") = " << result << endl;

    return 0;
}
