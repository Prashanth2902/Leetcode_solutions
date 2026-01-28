#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 78. Subsets
 * Link -> https://leetcode.com/problems/subsets/description/?q=subsets
 * 
 * Logic:-
 * Self explanatory code
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
        dfs(i+1, nums, res, subres);
    }
 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subres;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(0, nums, res, subres);
        return res;
    }
};