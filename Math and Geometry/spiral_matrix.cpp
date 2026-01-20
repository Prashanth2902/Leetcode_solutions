#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 54. Spiral Matrix
 * Link -> https://leetcode.com/problems/spiral-matrix/description/
 * 
 * Logic:-
 * This is a problem that requires high precision.
 * It is an easy problem. You just have to be careful.
 * 
 * Just keep 4 pointers that target each side of the matrix and then keep moving them inward.
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0;
        int left = 0; 
        int right = matrix[0].size();
        int bottom = matrix.size();
        while(left < right && top < bottom) {
            for(int i=left;i<right;i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<bottom;i++) {
                res.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(left < right && top < bottom)) break;
            for(int i=right-1;i>=left;i--) {
                res.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for(int i=bottom-1;i>=top;i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return res;
    }
};