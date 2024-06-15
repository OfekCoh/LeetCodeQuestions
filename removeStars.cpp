// You are given a string s, which contains stars *.
// In one operation, you can:
// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.
// Note:
// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

#include <iostream>
#include <string>

using namespace std;

string removeStars(string s) {
    int n = s.length();
    string res;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') res.pop_back();
        else res += s[i];
    }
    return res;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = removeStars(input);
    cout << "Resulting string after removing stars: " << result << endl;

    return 0;
}
