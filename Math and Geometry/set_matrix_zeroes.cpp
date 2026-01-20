#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 73. Set Matrix Zeroes
 * Link -> https://leetcode.com/problems/set-matrix-zeroes/description/
 * 
 * Logic:-
 * This is a simple problem.
 * You just have to 
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> rowzero(rows, false);
        vector<bool> colzero(cols, false);

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++) {
                if(matrix[r][c] == 0) {
                    rowzero[r] = true;
                    colzero[c] = true;
                }
            }
        }

        for(int r=0;r<rows;r++){
            if(rowzero[r]){
                for(int c=0;c<cols;c++){
                    matrix[r][c] = 0;
                }
            }
        }

        for(int c=0;c<cols;c++) {
            if(colzero[c]){
                for(int r=0;r<rows;r++){
                    matrix[r][c] = 0;
                }
            }
        }

    }
};