#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 70. Climbing Stairs
 * Link - https://leetcode.com/problems/climbing-stairs/description/
 * 
 * Logic :-
 * This is a simple Dp problem
 * The person can climb only 1 or 2 stairs at a time
 * if i goes beyond n, then return i;
 */

class Solution {
public:

    int dfs(int i, int n, vector<int>& cache) {
        if(i >= n) return i == n;
        if(cache[i] != -1) return cache[i];
        return cache[i] = dfs(i+1, n, cache) + dfs(i+2, n, cache);
    }

    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(0, n, cache);
    }
};