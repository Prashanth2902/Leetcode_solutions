#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 40. Combination Sum II
 * Link -> https://leetcode.com/problems/combination-sum-ii/description/?q=combination+sum
 * 
 * Logic:-
 * The array has elements that have duplicates. 
 * So we first have to sort the array.
 * If we find a duplicate, we just skip it
 */

class Solution {
public:

    void dfs(int i, vector<vector<int>>& res, vector<int>& subres, vector<int>& candidates, int target) {
        if(target == 0) {
            res.push_back(subres);
            return;
        }
        if(target < 0 || i == candidates.size()) return;
        subres.push_back(candidates[i]);
        dfs(i+1, res, subres, candidates, target - candidates[i]);
        subres.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        dfs(i+1, res, subres, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subres;
        dfs(0, res, subres, candidates, target);
        return res;
    }
};