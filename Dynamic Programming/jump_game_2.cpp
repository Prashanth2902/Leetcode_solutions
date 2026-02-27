#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 45. Jump Game II
 * Link -> https://leetcode.com/problems/jump-game-ii/description/
 * 
 * Logic:-
 * Again this is a standard DP.
 * If we go beyond the last index, just return INT_MAX.
 * This is similar to coin change problem
 */

class Solution {
public:
    int dfs(int i, vector<int>& cache, vector<int>& nums) {
        if(i >= nums.size()) return INT_MAX;
        if(i == nums.size() - 1) return 0;
        if(cache[i] != INT_MAX) return cache[i];
        int end = min((int) nums.size(), i + nums[i]);
        int ans = INT_MAX;
        for(int j=i+1;j<=end;j++) {
            int res = dfs(j, cache, nums);
            if(res != INT_MAX) {
                ans = min(ans, res + 1);
            }
        }
        return cache[i] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> cache(nums.size(), INT_MAX);
        return dfs(0, cache, nums);
    }
};
