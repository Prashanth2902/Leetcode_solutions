#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 90. Subsets II
 * Link -> https://leetcode.com/problems/subsets-ii/description/?q=subsets
 * 
 * Logic:-
 * The logic is similar to subsets, but the elements are repeated
 * If the elements are repeated, then we increment i if two adjacent elements are equal
 */


class Solution {
public:

    void dfs(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& subres) {
        if(i == nums.size()) {
            res.push_back(subres);
            return;
        }
        subres.push_back(nums[i]);
        dfs(i+1, nums, res, subres);
        subres.pop_back();
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        dfs(i+1, nums, res, subres);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subres;
        dfs(0, nums, res, subres);
        return res;
    }
};