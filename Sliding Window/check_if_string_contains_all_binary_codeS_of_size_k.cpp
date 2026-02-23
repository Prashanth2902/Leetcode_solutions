#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1461. Check If a String Contains All Binary Codes of Size K
 * Link -> https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
 * 
 * Logic:-
 * This is a simple sliding window problem.
 * All you gotta do is first create a set of strings.
 * Add substrings of s of size k in the set
 * If the set size equals 2^k, then its true
 * else its false
 */

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> checker;
        int l = 0;
        for(int r=k;r<=s.size();r++) {
            checker.insert(s.substr(l, k));
            l++;
        }
        if(checker.size() == pow(2,k)) return true;
        else return false;
    }
};