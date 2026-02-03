#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 647. Palindromic Substrings
 * Link - https://leetcode.com/problems/palindromic-substrings/description/
 * 
 * Logic:-
 * Start from one index in the middle that maintains palindrome prop. 
 * Expand in both directions. 
 * Account for odd and even strings.
 * If its a palindrome, increment res
 */

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++) {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
            l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};