#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 62. Unique Paths
 * Link -> https://leetcode.com/problems/unique-paths/description/
 * 
 * Logic:-
 * Standard 2D DP.
 * we have to compute the number of ways, so we add all cases.
 * 
 */

class Solution {
public:
    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& cache) {
        if(r == rows || c == cols) return 0;
        if(r == rows - 1 && c == cols - 1) return 1;
        if(cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = dfs(r+1, c, rows, cols, cache) + dfs(r, c+1, rows, cols, cache);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, cache);
    }
};