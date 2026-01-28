#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 22. Generate Parentheses
 * Link -> https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=plakya4j
 * 
 * Logic:-
 * We have to generate valid parenthesis in this problem.
 * n is the number of open and close parenthesis we have to generate.
 * Code is self explanatory
 */

class Solution {
public:

    void dfs(int n, vector<string>& res, string& subres, int open, int close) {
        if(open == close && open == n) {
            res.push_back(subres);
            return;
        }
        if(open < n) {
            subres.push_back('(');
            dfs(n, res, subres, open+1, close);
            subres.pop_back();
        }
        
        if(close < open) {
            subres.push_back(')');
            dfs(n, res, subres, open, close+1);
            subres.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subres;
        dfs(n, res, subres, 0, 0);
        return res;
    }
};