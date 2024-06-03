#include <iostream>
#include <string>
using namespace std;

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
// of the characters without disturbing the relative positions of the remaining characters. 
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

bool isSubsequence(string s, string t) {
    int ns=s.length();
    int nt=t.length();
    int i=0,j=0;
    if(ns>nt) return false;
    if(s==t) return true;
    for(i=0;i<nt;i++)
    {
        if(t[i]==s[j]) j++;
        if(j==ns) return true;
    }
    return false;
}


int main() {
    // Test cases
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";
    string s3 = "", t3 = "ahbgdc"; // empty s string
    string s4 = "ahbgdc", t4 = "ahbgdc"; // s and t are the same

    // Testing the function with the test cases
    cout << "Is '" << s1 << "' a subsequence of '" << t1 << "'? " << (isSubsequence(s1, t1) ? "Yes" : "No") << endl;
    cout << "Is '" << s2 << "' a subsequence of '" << t2 << "'? " << (isSubsequence(s2, t2) ? "Yes" : "No") << endl;
    cout << "Is '" << s3 << "' a subsequence of '" << t3 << "'? " << (isSubsequence(s3, t3) ? "Yes" : "No") << endl;
    cout << "Is '" << s4 << "' a subsequence of '" << t4 << "'? " << (isSubsequence(s4, t4) ? "Yes" : "No") << endl;

    return 0;
}