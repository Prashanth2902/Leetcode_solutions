#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3713. Longest Balanced Substring I
 * Link -> https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12
 * 
 * Logic:-
 * This is standard brute force problem.
 * check for all substrings.
 * store the longest answer
 */

class Solution {
public:
    bool eq(unordered_map<char, int>& m) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto i: m) {
            maxi = max(maxi, i.second);
            mini = min(mini, i.second);
        }
        return maxi == mini;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int res = INT_MIN;
        for(int i=0;i<n;i++) {
            unordered_map<char, int> m;
            for(int j=i;j<n;j++) {
                m[s[j]]++;
                if(eq(m)) {
                    res = max(res, j-i+1);
                }
            }
            m[s[i]]--;
            if(m[s[i]] == 0) {
                m.erase(s[i]);
            }
        }
        return res; 
    }
};