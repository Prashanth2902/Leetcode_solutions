#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1091. Shortest Path in Binary Matrix
 * Link -> https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 * 
 * Logic:-
 * Standard BFS for all 8 directions.
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(grid[0][0] != 0) return -1;

        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        visit[0][0] = true;
        
        vector<vector<int>> dirs = {
            {1,1},
            {-1,-1},
            {1,-1},
            {-1,1},
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(get<0>(curr) == rows - 1 && get<1>(curr) == cols - 1) {
                return get<2>(curr);
            }
            for(int i=0;i<8;i++) {
                int nr = get<0>(curr) + dirs[i][0];
                int nc = get<1>(curr) + dirs[i][1];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if(grid[nr][nc] == 0 && !visit[nr][nc]) {
                        q.push({nr, nc, get<2>(curr)+1});
                        visit[nr][nc] = true;
                    }
                }
            }
        }
        return -1;
    }
};