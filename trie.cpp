// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
// There are various applications of this data structure, such as autocomplete and spellchecker.

#include <iostream>
#include<vector>
using namespace std;

class Trie {
private:
    vector<Trie*> letters;
    bool isWord;  // checks if the word ended in that tri (and not just a prefix)
    
public:
    Trie(): letters(26,nullptr), isWord(false){}
    
    void insert(string word) {
        Trie* curr=this;

        for(auto x : word)
        {
            int i=int(x)-97;
            if(!curr->letters[i]) curr->letters[i]= new Trie;  // if the entrance for the letter is null, create a new trie. else just continue.
            curr=curr->letters[i];
        }        
        curr->isWord=true;
    }
    
    bool search(string word) {
        Trie* curr=this;
        for(auto x : word)
        {
            int i=int(x)-97;
            if(!curr->letters[i]) return false;  // if the entrance for the letter is null, create a new trie. else just continue.
            curr=curr->letters[i];
        }    
        if(!curr->isWord) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Trie* curr=this;
        for(auto x : prefix)
        {
            int i=int(x)-97;
            if(!curr->letters[i]) return false;  // if the entrance for the letter is null, create a new trie. else just continue.
            curr=curr->letters[i];
        }    
        return true;
    }

};

int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout<< trie->search("apple") <<endl;   // return True
    cout<< trie->search("app") <<endl;     // return False
    cout<< trie->startsWith("app") <<endl; // return True
    trie->insert("app");
    cout<< trie->search("app") <<endl;  

    return 0;
}
