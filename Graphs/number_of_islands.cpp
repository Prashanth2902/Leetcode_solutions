#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 200. Number of Islands
 * Link -> https://leetcode.com/problems/number-of-islands/description/
 * 
 * Logic:-
 * An island is a piece of land that is surrounded by water.
 * So what we do here is if we find a piece of land. we increment our answer and sink the land.
 * The dfs function handles the sinking part.
 * 
 *  */

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(min(r, c) < 0 || r == rows || c == cols || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '1') {
                    res++;
                    dfs(grid, r, c);
                }
            }
        }
        return res;
    }
};