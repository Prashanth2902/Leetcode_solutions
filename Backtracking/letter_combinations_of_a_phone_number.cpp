#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 17. Letter Combinations of a Phone Number
 * Link -> https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * 
 * Logic:-
 * This is a simple backtracking soln
 * All we need to do is first initialize the digitToChar DS.
 * Then we need to just do backtracking while iterating
 * over the length of the string from digitsToChar
 */

class Solution {
public:

    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};


    void dfs(int i, vector<string>& res, string subres, string digits) {
        if(subres.size() == digits.size()) {
            res.push_back(subres);
            return;
        }
        if(i > digits.size()) return;
        for(auto c: digitToChar[digits[i] - '0']) {
            dfs(i+1, res, subres+c, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string subres;
        dfs(0, res, subres, digits);
        return res;
    }
};