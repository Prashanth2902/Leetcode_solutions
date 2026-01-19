#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 91. Decode Ways
 * Link -> https://leetcode.com/problems/decode-ways/description/
 * 
 * Logic:-
 * The crux of this logic is to include either 1 or 2 letters.
 * If its just 1 letter, we increment the iterator
 */

class Solution {
public:

    int dfs(int i, string s, unordered_map<int,int>& m) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(m.count(i)) return m[i];

        int skip = dfs(i+1, s, m);

        if(i+1 < s.size() && 
        ((s[i] == '1') || (s[i] == '2' && s[i+1] <= '6'))) {
            skip += dfs(i+2, s, m);
        }
        return m[i] = skip;
    }

    int numDecodings(string s) {
        unordered_map<int,int> m;
        m[s.size()] = 1;
        return dfs(0, s, m);
    }
};