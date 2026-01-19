#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 * Link -> https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19
 * 
 * Logic:-
 * This problem uses prefix sum but in 2D form.
 * We first populate the prefix array by subtracting the top and left value
 * and then adding the top left value of prefix array and matrix.
 * Then while calculating we try to find the sum of all elements upto a specific row and column.
 * That is done by current - top - left + topleft.
 * If that is less than or equal to threshold, then thats our side so far.
 * Repeat this till we keep increasing side length.
 */

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefix(rows+1, vector<int>(cols+1, 0));

        for(int r=1;r<=rows;r++){
            for(int c=1;c<=cols;c++){
                prefix[r][c] = prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1] + mat[r-1][c-1];
            }
        }

        int res = 0;
        
        for(int r=1;r<=rows;r++) {
            for(int c=1;c<=cols;c++){
                int k = res + 1;
                if(r >= k && c >= k) {
                    int currSum = prefix[r][c] - prefix[r-k][c] - prefix[r][c-k] + prefix[r-k][c-k];
                    if(currSum <= threshold) {
                        res = k;
                    } 
                }
            }
        }
        return res;
    }
};