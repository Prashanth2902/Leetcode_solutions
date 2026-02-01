#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 994. Rotting Oranges
 * Link -> https://leetcode.com/problems/rotting-oranges/description/
 * 
 * Logic:-
 * So we use BFS for this problem.
 * We insert all coords for rotten oranges into the queue.
 * We then keep rotting the fresh oranges through BFS.
 * 
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(fresh > 0 && !q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto curr = q.front();
                q.pop();
                int cr = curr.first;
                int cc = curr.second;
                for(int j=0;j<4;j++) {
                    int nr = cr + dirs[j][0];
                    int nc = cc + dirs[j][1];
                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()
                        && grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            fresh--;
                            q.push({nr, nc});
                        }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};