class Trie {
private:
    vector<Trie*> letters;
    bool ends;  // checks if the word ended in that tri (and not just a prefix)
    
public:
    Trie(): letters(26,nullptr), ends(false){}
    
    void insert(string word) {
        Trie* curr=this;

        for(auto x : word)
        {
            int i=int(x)-97;
            if(!curr->letters[i]) curr->letters[i]= new Trie;  // if the entrance for the letter is null, create a new trie. else just continue.
            curr=curr->letters[i];
        }        
        curr->ends=true;
    }
    
    bool search(string word) {
        Trie* curr=this;
        for(auto x : word)
        {
            int i=int(x)-97;
            if(!curr->letters[i]) return false;  // if the entrance for the letter is null, create a new trie. else just continue.
            curr=curr->letters[i];
        }    
        if(!curr->ends) return false;
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