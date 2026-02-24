#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 542. 01 Matrix
 * Link -> https://leetcode.com/problems/01-matrix/description/
 * 
 * Logic:-
 * Push all 0 values into a queue.
 * If init value is not 0, set it as INT_MAX(for unvisited nodes).
 * Then when doing BFS, if value is unvisited, add 1 from the current Node(init value would be 0).
 * 
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int rows = mat.size();
        int cols = mat[0].size();
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(mat[r][c] == 0) {
                    q.push({r, c});
                } else {
                    mat[r][c] = INT_MAX;
                }
            }
        }
        while(!q.empty()) {
            auto [r1, c1] = q.front();
            q.pop();
            for(auto d: directions) {
                int r2 = r1 + d[0], c2 = c1 + d[1];
                if(r2 >= 0 && c2 >= 0 && r2 < rows && c2 < cols) {
                    if(mat[r2][c2] == INT_MAX) {
                        mat[r2][c2] = 1 + mat[r1][c1];
                        q.push({r2, c2});
                    }
                }
            }
        }
        return mat;
    }
};