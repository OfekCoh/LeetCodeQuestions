#include <iostream> 
#include <string>
using namespace std;

//You are given two strings word1 and word2.
//Merge the strings by adding letters in alternating order, starting with word1.
//If a string is longer than the other, append the additional letters onto the end of the merged string.
//Return the merged string.

string mergeAlternately(string word1, string word2) {
    int k=0, i=0, j=0;
    int len1=word1.length();
    int len2=word2.length();
    int n=len1+len2;
    string res="";
    while(k<n)
    {
        if(i<len1) 
        {
            res+=word1[i++];
            k++;
        }
        if(j<len2){
            res+=word2[j++];
            k++;
        } 
    }
    return res;
}

int main() {
    string word1 = "abc";
    string word2 = "defgh";
    string result = mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;
    return 0;
}