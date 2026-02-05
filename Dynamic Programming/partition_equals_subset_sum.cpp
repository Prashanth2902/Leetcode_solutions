#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 416. Partition Equal Subset Sum
 * Link -> https://leetcode.com/problems/partition-equal-subset-sum/description/
 * 
 * Logic:-
 * So the crux of this problem is we need to find just one subset.
 * That subset should equal half of the total sum of the array.
 * So we do standard backtracking to find the subset.
 * We follow 0/1 knapsack methodology. 
 */

class Solution {
public:

    bool dfs(int i, vector<int>& nums, int target, vector<vector<int>>& cache) {
        if(i >= nums.size()) return false;
        if(target < 0) return false;
        if(target == 0) return true;
        if(cache[i][target] != -1) return cache[i][target];
        return cache[i][target] = dfs(i+1, nums, target, cache) || dfs(i+1, nums, target - nums[i], cache); 
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum%2 != 0) return false;
        vector<vector<int>> cache(nums.size(), vector<int>(sum/2 + 1, -1));
        return dfs(0, nums, sum/2, cache);
    }
};