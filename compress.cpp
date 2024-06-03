#include <iostream> 
#include <string>
#include <vector>
using namespace std;


// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
//Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.

int compress(vector<char>& chars) {
    int n=chars.size();
    if(n==1) return 1;
    int i, j=0, count=1;
    for(i=1;i<n;i++)
    {
        if(chars[i]!=chars[i-1])
        {
            chars[j++]=chars[i-1];
            if(count>1)
            {
                string countStr = to_string(count);
            for (char c : countStr) {
                chars[j++] = c;
            }
                count=1;
            }
            if(i==n-1) chars[j++]=chars[i];
        }
        else
        {
            count++;
            if(i==n-1)
            {
                chars[j++]=chars[i];
                string countStr = to_string(count);
            for (char c : countStr) {
                chars[j++] = c;
            }
            }
        }
    }
    return j;
    }

    int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);

    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; ++i) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}