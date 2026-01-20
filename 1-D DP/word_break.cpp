#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 139. Word Break
 * Link -> https://leetcode.com/problems/word-break/description/
 * 
 * Logic:-
 * This looks hard but basically we just have to check if we reach the end of the string
 * using just words from the dictionary.
 * We use a map to track the current position of i to a boolean
 */

class Solution {
public:

    bool dfs(int i, string s, vector<string>& wordDict, unordered_map<int, bool>& m) {
        if(i == s.size()) return true;
        if(m.count(i)) return m[i];

        for(string word: wordDict) {
            if(i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
                if(dfs(i+word.size(), s, wordDict, m)) {
                    m[i] = true;
                    return true;
                }
            }
        }

        return m[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> m;
        m[s.size()] = true;
        return dfs(0, s, wordDict, m);
    }
};