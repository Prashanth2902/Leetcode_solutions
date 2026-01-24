#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 76. Minimum Window Substring
 * Link -> https://leetcode.com/problems/minimum-window-substring/
 * 
 * Logic :-
 * We need to use two hashmaps, one for each string.
 * Initially we populate the string t hashmap (tCount)
 * then we initialize two variables that handle the number of unique characters of each string
 * the we initialize the maxLen which keeps track of the maximum length of the result string
 * res handles the start and end index of the string.
 * once our have and need variables are equal, then we can start moving the left pointer
 * We then print the answer from the valid res
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, tCount;
        for(int i=0;i<t.size();i++) tCount[t[i]]++;
        int have = 0, need = tCount.size();
        int l = 0;
        int maxLen = INT_MAX;
        pair<int,int> res = {-1, -1};
        for(int r=0;r<s.size();r++) {
            char a = s[r];
            window[a]++;
            if(tCount.count(a) && window[a] == tCount[a]) have++;
            while(have == need) {
                if(maxLen > (r-l+1)) {
                    maxLen = r-l+1;
                    res = {l, r};
                }
                char x = s[l];
                window[x]--;
                l++;
                if(tCount.count(x) && window[x] < tCount[x]) have--; 
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(res.first, maxLen);
    }
};