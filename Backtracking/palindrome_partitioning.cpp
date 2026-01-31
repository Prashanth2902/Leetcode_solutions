#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 131. Palindrome Partitioning
 * Link -> https://leetcode.com/problems/palindrome-partitioning/description/
 * 
 * Logic:-
 * So first we need to check the number of palindromes that are possible 
 * starting from each index i of string.
 * We then check for each substring of length j-i+1.
 * If i goes out of bounds, we then add the subres to res 
 */

class Solution {
public:

    bool isPalin(string s) {
        int l = 0, r = s.size() - 1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(int i, vector<vector<string>>& res, vector<string>& subres, string s) {
        if(i >= s.size()) {
            res.push_back(subres);
            return;
        }
        for(int j=i;j<s.size();j++) {
            if(isPalin(s.substr(i, (j-i+1)))) {
                subres.push_back(s.substr(i, j-i+1));
                dfs(j+1, res, subres, s);
                subres.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> subres;
        vector<vector<string>> res;
        dfs(0, res, subres, s);
        return res;
    }
};
