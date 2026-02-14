#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 799. Champagne Tower
 * Link -> https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14
 * 
 * Logic:-
 * This is essentially a simulation of the problem.
 */

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double tower[102][102] = {0.0};
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};