int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;
    vector<int> hist(128,0); //ascii size hist
    int longest=0, j=0;

    for(int i=0;i<s.length();i++) {
        hist[s[i]]++;

        if(hist[s[i]]>1) {
            while(j<i) {
                hist[s[j]]--;
                j++;
                if(s[j-1]==s[i]) break;
            } 
        }

        else if(longest<(i-j+1)) longest=(i-j+1);
    }

    return longest;
}