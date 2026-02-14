#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3839. Number of Prefix Connected Groups
 * Link -> https://leetcode.com/problems/number-of-prefix-connected-groups/description/
 * 
 * Logic:-
 * We group words by prefix.
 * If the size of vector more than 1. then add 1 to result.
 * return result
 */

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, vector<string>> ds;
        for(auto word: words) {
            if(word.size() >= k) {
                string pref = word.substr(0, k);
                ds[pref].push_back(word);
            }
        }
        int res = 0;
        for(auto i: ds) {
            vector<string> count = i.second;
            if(count.size() > 1) res++;
        }
        
        return res;
    }
};