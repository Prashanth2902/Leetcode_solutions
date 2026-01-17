#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 49. Group Anagrams
 * Link -> https://leetcode.com/problems/group-anagrams/description/?q=group+anagrams
 * 
 * Logic:-
 * This is another simple usage of hashmap.
 * We group strings based on their words.
 * We map a sorted string as the key and then its anagrams as the values.
 * We then return the values.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringmap;
        for(auto s: strs) {
            string keystring = s;
            sort(keystring.begin(), keystring.end());
            stringmap[keystring].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& pair : stringmap) {
            res.push_back(pair.second);
        }
        return res;
    }
};