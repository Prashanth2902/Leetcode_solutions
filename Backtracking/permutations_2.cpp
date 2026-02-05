#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 47. Permutations II
 * Link -> https://leetcode.com/problems/permutations-ii/description/
 * 
 * Logic:-
 * This logic is similar to permutations 1 but the elements have duplicates.
 * We again keep a visited array for each index in the nums vector.
 * Since we have duplicates, we need to attend to this problem carefully.
 * We should skip those sub problems if the previous visited of the same element
 * has already been visited.
 * This means that all elements of the same number has been solved.
 */

class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subres, vector<bool>& visited) {
        if(subres.size() == nums.size()) {
            res.push_back(subres);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(visited[i]) continue;
            if(i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue;
            subres.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, res, subres, visited);
            subres.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subres;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, subres, visited);
        return res;
    }
};