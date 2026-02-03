#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 746. Min Cost Climbing Stairs
 * Link -> https://leetcode.com/problems/min-cost-climbing-stairs/description/
 * 
 * Logic:-
 * This is standard backtracking problem
 */

class Solution {
public:

    int dfs(int i, vector<int>& cost, vector<int>& cache) {
        if(i >= cost.size()) return 0;
        if(cache[i] != INT_MAX) return cache[i];
        return cache[i] = cost[i] + min(dfs(i+1, cost, cache), dfs(i+2, cost, cache));
    }
 
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size() + 1, INT_MAX);
        return min(dfs(0, cost, cache), dfs(1, cost, cache));
    }
};
