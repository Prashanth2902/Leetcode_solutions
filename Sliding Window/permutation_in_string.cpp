#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 567. Permutation in String
 * Link -> https://leetcode.com/problems/permutation-in-string/description/
 * 
 * Logic:-
 * We can check this with simple two hashmaps and sliding window.
 * code is self explanatory
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for(int i=0;i<s1.size();i++){
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        for(int i=0;i<s2.size() - s1.size();i++) {
            if(s1Count == s2Count) return true;
            s2Count[s2[i + s1.size()] - 'a']++;
            s2Count[s2[i] - 'a']--;
        }

        return s1Count == s2Count; 
    }
};
