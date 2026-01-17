#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 417. Pacific Atlantic Water Flow
 * Link -> https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 * 
 * Logic :-
 * The problem is there is a piece of land that splits the pacific ocean and the atlantic ocean.
 * We need to find the piece of land.
 * the piece of land has its index value greater than both values in pacific and atlantic ocean.
 * 
 * We create two 2D sets initialized to false that check if the condition is valid. One for pacific and one for atlantic.
 * We then call the dfs function from the top and the left for pacific and then bottom and right for atlantic.
 * If the resultant 2D sets have true in both the index, then that index is a piece of land. 
 * The r and c will be pushed into the result array.
 * 
 * The logic of the dfs is simple. For a given r and c, we mark it as true in the hashset.
 * When we are traversing in the 4 directions, we need to make sure if the next index value is higher than the current index.
 * If it is higher and has not been visited then traverse to the next index.
 */

class Solution {
private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visit) {
        int rows = heights.size();
        int cols = heights[0].size();
        visit[r][c] = true;
        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto [dr, dc]: directions) {
            int nr = r + dr, nc = c + dc;
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols 
               && heights[nr][nc] >= heights[r][c] && !visit[nr][nc]){
                dfs(heights, nr, nc, visit);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++) {
            dfs(heights, r, 0, pac);
            dfs(heights, r, cols-1, atl);
        }

        for(int c = 0; c < cols; c++) {
            dfs(heights, 0, c, pac);
            dfs(heights, rows-1, c, atl);
        }

        vector<vector<int>> res;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};