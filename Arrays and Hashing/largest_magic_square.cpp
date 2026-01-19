#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1895. Largest Magic Square
 * Link -> https://leetcode.com/problems/largest-magic-square/description/
 * 
 * Logic:-
 * A magic square is a square where, rows, columns and diagonals have the same sum.
 * 
 * Initially we calculate the prefix sums for rows and columns.
 * Then we start from largest possible square and keep iterating over all squares.
 */

class Solution {
public:

    bool isMagic(vector<vector<int>>& grid, vector<vector<int>>& rowsum, 
    vector<vector<int>>& colsum, int r, int c, int k) {
        int target = rowsum[r][c+k] - rowsum[r][c];
        for(int i = r+1; i < r + k; i++) {
            if(target != rowsum[i][c+k] - rowsum[i][c]) return false;
        }
        for(int i = c+1; i < c + k; i++) {
            if(target != colsum[i][r+k] - colsum[i][r]) return false;
        }
        int diag1 = 0;
        for(int i=0;i<k;i++) {
            diag1 += grid[r+i][c+i];
        }
        if(diag1 != target) return false;
        int diag2 = 0;
        for(int i=0;i<k;i++) {
            diag2 += grid[r+i][c+k-1-i];
        }
        if(diag2 != target) return false;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> rowsum(rows, vector<int>(cols+1, 0));
        vector<vector<int>> colsum(cols, vector<int>(rows+1, 0));

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                rowsum[i][j+1] = rowsum[i][j] + grid[i][j];
                colsum[j][i+1] = colsum[j][i] + grid[i][j];
            }
        }

        for(int k = min(rows, cols); k > 1; k--) {
            for(int i=0;i<=rows-k;i++) {
                for(int j=0;j<=cols-k;j++) {
                    if(isMagic(grid, rowsum, colsum, i, j, k)) return k;
                }
            }
        }
        return 1;
    }
};