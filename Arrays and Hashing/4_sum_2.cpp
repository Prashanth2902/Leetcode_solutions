#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 454. 4Sum II
 * Link -> https://leetcode.com/problems/4sum-ii/description/
 * 
 * Logic:-
 * So we need to find 4 numbers in each of these arrays that add to 0.
 * ie. a+b+c+d = 0. 
 * This could also mean that a+b = -(c+d).
 * So first we store a+b in map,
 * then we find -(c+d) in the map and its freq to the res.
 * Return the res later
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        unordered_map<int, int> m;
        for (int a : A) {
            for (int b : B) {
                ++m[a + b];
            }
        }
        
        for (int c : C) {
            for (int d : D) {
                if (m.find(-(c + d)) != end(m)) {
                    cnt += m[-(c+d)];
                }
            }    
        }
        return cnt;
    }
};