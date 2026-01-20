#include<bits/stdc++.h>
using namespace std;\

/**
 * Leetcode Medium
 * Problem - 198. House Robber
 * Link -> https://leetcode.com/problems/house-robber/description/?q=house+robber
 * 
 * Logic:-
 * This is a standard backtracking logic implementation.
 * The robber can only pick either the current house and go to i+2 house.
 * Or skip the current house.
 */

class Solution {
public:

    int dfs(int i, vector<int>& nums, vector<int>& cache) {
        if(i >= nums.size()) return 0;
        if(cache[i] != -1) return cache[i];
        int skip = dfs(i+1, nums, cache);
        int include = nums[i] + dfs(i+2, nums, cache);
        return cache[i] = max(skip, include);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        return dfs(0, nums, cache);
    }
};