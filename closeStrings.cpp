// Two strings are considered close if you can attain one from the other using the following operations:
// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, 
// and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.
// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) return false;
    
    unordered_map<char, int> map1, map2;
    
    for (char c : word1) {
        map1[c]++;
    }
    
    for (char c : word2) {
        map2[c]++;
    }
    
    for (const auto& pair : map2) {
        if (map1.find(pair.first) == map1.end()) return false;
    }
    
    for (const auto& pair : map1) {
        if (map2.find(pair.first) == map2.end()) return false;
    }
    
    multiset<int> set1, set2;
    
    for (const auto& pair : map1) {
        set1.insert(pair.second);
    }
    
    for (const auto& pair : map2) {
        set2.insert(pair.second);
    }
    
    return set1 == set2;
}

int main() {
    string word1 = "abc";
    string word2 = "bca";
    
    bool result = closeStrings(word1, word2);
    
    cout << "The words \"" << word1 << "\" and \"" << word2 << "\" are close strings: " << (result ? "true" : "false") << endl;

    return 0;
}
