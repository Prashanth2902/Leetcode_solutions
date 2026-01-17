#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 242. Valid Anagram
 * Link -> https://leetcode.com/problems/valid-anagram/description/?q=valid+anagram
 * 
 * Logic:-
 * Anagrams should have same frequency of letters.
 * We use a hashmap to solve this.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> charmap;
        for(int i=0;i<s.size();i++){
            charmap[s[i]]++;
            charmap[t[i]]--;
        }
        for(auto i: charmap) {
            if(i.second != 0) return false;
        }
        return true;
    }
};