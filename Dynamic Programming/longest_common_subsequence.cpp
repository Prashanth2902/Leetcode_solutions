#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1143. Longest Common Subsequence
 * Link -> https://leetcode.com/problems/longest-common-subsequence/description/
 * 
 * Logic:-
 * Standard 2D DP.
 * If characters match, then add 1 to cache and increment idx of both.
 * If not then return max with either idx incremented
 */

class Solution {
public:

    int dfs(int i, int j, string& s1, string& s2, vector<vector<int>>& cache) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(cache[i][j] != -1) return cache[i][j];
        if(s1[i] == s2[j]) {
            cache[i][j] = 1 + dfs(i+1, j+1, s1, s2, cache);
        } else {
            cache[i][j] = max(dfs(i, j+1, s1, s2, cache), dfs(i+1, j, s1, s2, cache));
        }
        return cache[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0, text1, text2, cache);
    }
};