#include <iostream> 
#include <string>
using namespace std;

// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


string reverseVowels(string s) {
    string n="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
        || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            n+=s[i];
        }
    }
    int j=n.length()-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
        || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            s[i]=n[j--];
        }
    }
    return s;
}

int main() {
    string s1 = "hello";
    string s2 = "leetcode";
    
    cout << "Original: " << s1 << " -> Reversed Vowels: " << reverseVowels(s1) << endl;
    cout << "Original: " << s2 << " -> Reversed Vowels: " << reverseVowels(s2) << endl;

    return 0;
}