#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 125. Valid Palindrome
 * Link -> https://leetcode.com/problems/valid-palindrome/description/
 * 
 * Logic:-
 * Simple l, r pointer impl
 */

class Solution {
public:

    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            while(l < r && !isAlphaNum(s[l])) l++;
            while(l < r && !isAlphaNum(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};