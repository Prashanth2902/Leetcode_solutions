#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 5. Longest Palindromic Substring
 * Link - https://leetcode.com/problems/longest-palindromic-substring/description/
 * 
 * Logic:-
 * Start from one index in the middle that maintains palindrome prop. 
 * Expand in both directions. 
 * Account for odd and even strings.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        pair<int,int> res = {-1, -1};
        for(int i=0;i<s.size();i++) {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(maxLen < (r-l+1)) {
                    maxLen = r-l+1;
                    res = {l, r};
                }
                l--;
                r++;
            }
            l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(maxLen < (r-l+1)) {
                    maxLen = r-l+1;
                    res = {l, r};
                }
                l--;
                r++;
            }
        }
        return s.substr(res.first, maxLen);
    }
};