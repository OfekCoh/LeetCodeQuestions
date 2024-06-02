#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.

string reverseWords(string s) {
    vector<string> arr;
    string temp="";
    bool word=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ' && word==true){
            word=false;
            arr.push_back(temp);
            temp="";
        }
        if(s[i]!=' '){
            if(!word) word=true;
            temp+=s[i];
            if(i==s.length()-1) arr.push_back(temp);
        }
    }
    string res="";
    for (int i = arr.size() - 1; i >= 0; --i) {
        res+= arr[i];
        if(i!=0) res+=' ';
    }
    return res;
}

int main() {
    string input = "the sky is blue";
    string result = reverseWords(input);
    cout << "Reversed words: \"" << result << "\"" << endl;
    return 0;
}