#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 249. Group Shifted Strings
 * Link -> https://leetcode.com/problems/group-shifted-strings/description/
 * 
 * Logic:-
 * So we have to group strings that have similar properties.
 * So we need to encode the strings that follow this property.
 * Thats what the shifter function does.
 * 
 * The shifter function calculates the distance between each character.
 *  
 * Then just return the strings in sorted order that follow this property.
 */


class Solution {
public:

    string shifter(string s) {
        string t;
        int n = s.size();
        for(int i=1;i<n;i++) {
            int diff = s[i] - s[i-1];
            if(diff < 0) diff += 26;
            t += 'a' + diff + ',';
        }
        return t;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for(auto s: strings) {
            m[shifter(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto i: m) {
            sort(i.second.begin(), i.second.end());
            res.push_back(i.second);
        }
        return res;
    }
};