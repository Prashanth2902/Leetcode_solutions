#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 213. House Robber II
 * Link -> https://leetcode.com/problems/house-robber-ii/description/?q=house+robber
 * 
 * Logic:-
 * This logic is similar to house robber 1, but the houses are in a circle.
 * So we have to maintain two caches and compute dfs method twice
 * It is done in such a way to treat each dfs method as house robber 1 implementation
 */

class Solution {
public:

    int dfs(vector<int>& nums, vector<int>& cache, int l, int r) {
        if(l > r) return 0;
        if(cache[l] != -1) return cache[l];
        int skip = dfs(nums, cache, l+1, r);
        int include = nums[l] + dfs(nums, cache, l+2, r);
        return cache[l] = max(skip, include);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(dfs(nums, dp1, 1, n-1), dfs(nums, dp2, 0, n-2));
    }
};