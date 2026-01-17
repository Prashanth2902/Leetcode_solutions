#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem Name = 271. Encode and Decode strings.
 * 
 * Logic :-
 * For the encode function, we just create an empty string and append the length of the word,
 * a delimiter like '#' and then the actual word. 
 * For example, the array -> ["Hello", "World"] would looke like "5#Hello5#World".
 * 
 * For the decode function, this is the tricky part of the problem.
 * We first initialize a variable i to traverse the entire string.
 * Then we initialize another variable j to find key information in the string.
 * 1) First we try to find the first occurence of the delimiter.
 * 2) Then we get the length of the word (i->j is the word length).
 * Now we know the next position of j is the starting letter of the word.
 * Since we have the starting position and the word length, we can create a substring
 * We then push this substring into the resultant vector.
 */

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;
        for(auto str: strs) {
            res += to_string(str.length()) + '#' + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if(s.empty()) return res;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int strlen = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j + 1, strlen));
            i = j + 1 + strlen;
        }
        return res;
    }
};
