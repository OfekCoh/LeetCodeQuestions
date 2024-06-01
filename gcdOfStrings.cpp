#include <iostream> 
#include <string>
#include <numeric>
using namespace std;

//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1)? 
    str1.substr(0, gcd(size(str1),size(str2))): "";
}

int main() {
    string str1 = "ABCABC";
    string str2 = "ABC";
    
    string result = gcdOfStrings(str1, str2);
    cout << "GCD of strings: " << result << endl;

    return 0;
}