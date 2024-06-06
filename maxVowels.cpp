#include <iostream>
#include <string>
using namespace std;

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

int maxVowels(string s, int k) {
    int max=0, temp=0;
    for(int i=0; i<k;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') 
            temp++;
    }
    max=temp;
    for(int i=k; i<s.length();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') 
            temp++;
        if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u') 
            temp--;
        if(max<temp) max=temp;
    }
    return max;
}

int main() {
    string s = "abciiidef";
    int k = 3;
    cout << "Maximum number of vowels in any substring of length " << k << " is: " << maxVowels(s, k) << endl;
    return 0;
}