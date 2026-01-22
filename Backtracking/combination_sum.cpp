#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 39. Combination Sum
 * Link -> https://leetcode.com/problems/combination-sum/description/
 * 
 * Logic:-
 * This problem is a standard backtracking problem.
 * Here we see that a specific candidate can be used multiple times to reach a target
 * A candidate can also combine with other candidates to reach the target.
 * So initially we add a candidate to the sub result and then call dfs with target - candidate.
 * Or we pop the candidate from the sub result and then move onto the next candidate
 */

class Solution {
public:

    void dfs(int i, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& subres) {
        if(target == 0) {
            res.push_back(subres);
            return;
        }
        if(target < 0 || i == candidates.size()) return;
        subres.push_back(candidates[i]);
        dfs(i, candidates, target - candidates[i], res, subres);
        subres.pop_back();
        dfs(i+1, candidates, target, res, subres);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        dfs(0, candidates, target, res, subres);
        return res;
    }
};