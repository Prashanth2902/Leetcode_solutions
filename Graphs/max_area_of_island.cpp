#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 695. Max Area of Island
 * Link -> https://leetcode.com/problems/max-area-of-island/description/
 * 
 * Logic:-
 * This logic is similar to number of islands.
 * If we spot a 1, then we find the max area of that island and then sink the island.
 * Then we return the max area
 */

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(min(r,c) < 0 || r == rows || c == cols || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int result = 1 +
             dfs(grid, r+1, c) + 
             dfs(grid, r-1, c) + 
             dfs(grid, r, c+1) + 
             dfs(grid, r, c-1);
        return result;   
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] == 1) {
                    ans = max(ans, dfs(grid, r, c));
                }
            }
        }
        return ans;
    }
};
