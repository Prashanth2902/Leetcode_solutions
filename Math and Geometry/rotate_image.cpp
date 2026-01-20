#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 48. Rotate Image
 * Link -> https://leetcode.com/problems/rotate-image/description/
 * 
 * Logic:-
 * To rotate 90 degree clockwise, reverse the matrix rows,
 * and then swap elements where j > i
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        reverse(matrix.begin(), matrix.end());

        for(int r=0;r<rows;r++) {
            for(int c=r+1;c<cols;c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};
