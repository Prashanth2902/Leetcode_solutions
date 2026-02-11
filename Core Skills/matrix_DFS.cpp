#include<bits/stdc++.h>
using namespace std;

/**
 * You are given a binary matrix Grid where 0s represent land and 1s represent rocks that can not be traversed. 
 * Return the number of unique paths from the top-left corner of Grid to the bottom-right corner such that 
 * all traversed cells are land cells. You may only move vertically or horizontally through land cells. 
 * 
 * For an individual unique path you cannot visit the same cell twice.
 */

class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c, int& res, vector<vector<bool>>& visit) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(min(r,c) < 0 || r == rows || c == cols) return;
        if(grid[r][c] == 1) return;
        if(visit[r][c]) return;
        if(r == rows-1 && c == cols-1) {
            res++;
            return;
        }
        visit[r][c] = true;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto [dr,dc] : directions) {
            int nr = r + dr, nc = c + dc;
            dfs(grid, nr, nc, res, visit);
        }
        visit[r][c] = false;
    }

    int countPaths(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, 0, 0, res, visit);
        return res;
    }
};
