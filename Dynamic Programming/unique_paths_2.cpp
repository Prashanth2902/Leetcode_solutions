#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 63. Unique Paths II
 * Link -> https://leetcode.com/problems/unique-paths-ii/description/?q=unique+paths
 * 
 * Logic:-
 * This is similar to Unique Paths 1.
 * Just account for obstacle. If encountered, return 0.
 * 
 */

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols, vector<vector<int>>& cache) {
        if(r == rows || c == cols || grid[r][c] == 1) return 0;
        if(r == rows-1 && c == cols-1) return 1;
        if(cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = dfs(grid, r+1, c, rows, cols, cache) + dfs(grid, r, c+1, rows, cols, cache); 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> cache(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, 0, 0, obstacleGrid.size(), obstacleGrid[0].size(), cache);
    }
};