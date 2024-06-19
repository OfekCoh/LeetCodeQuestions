// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
// Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces, 
// square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any 
// digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    bool isLetter(char x) {
        return (x >= 'a' && x <= 'z');
    }

    bool isNum(char x) {
        return (x >= '0' && x <= '9');
    }

    string decodeString(string s) {
        vector<int> nums;
        vector<string> temp;
        string res;
        
        for(int i = 0; i < s.length(); i++) {
            char x = s[i];
            if(isLetter(x)) {
                if(temp.empty()) res += x;
                else temp.back() += x;
            } else if(x == '[') {
                temp.push_back("");
            } else if(x == ']') {
                string str = temp.back();
                temp.pop_back();
                int count = nums.back();
                nums.pop_back();
                string repeatedStr = "";
                for(int j = 0; j < count; j++) {
                    repeatedStr += str;
                }
                if(temp.empty()) res += repeatedStr;
                else temp.back() += repeatedStr;
            } else {  // x is a number
                int num = 0;
                while(i < s.length() && isNum(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // step back to not skip the '['
                nums.push_back(num);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<string> testCases = {
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "abc3[cd]xyz"
    };

    // Loop through each test case and print the results
    for(auto& testCase : testCases) {
        cout << "Input: " << testCase << endl;
        string result = solution.decodeString(testCase);
        cout << "Output: " << result << endl << endl;
    }
    
    return 0;
}
