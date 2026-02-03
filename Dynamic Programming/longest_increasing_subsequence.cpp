#include<bits/stdc++.h>
using namespace std;\

/**
 * Leetcode Medium
 * Problem - 300. Longest Increasing Subsequence
 * Link -> https://leetcode.com/problems/longest-increasing-subsequence/
 * 
 * Logic:-
 * This is a mix of dp and two pointer imo.
 * DP in terms of memo
 * two pointer in terms of comparing two elements in array.
 * It is then standard backtracking implementation.
 */


class Solution {
public:

    int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& cache) {
        if(i == nums.size()) return 0;
        if(cache[i][j+1] != -1) return cache[i][j+1];

        int res = dfs(i+1, j, nums, cache);

        if(j == -1 || nums[j] < nums[i]) {
            res = max(res, 1 + dfs(i+1, i, nums, cache));
        }

        return cache[i][j+1] = res;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache(n, vector<int>(n+1, -1));
        return dfs(0, -1, nums, cache);
    }
};