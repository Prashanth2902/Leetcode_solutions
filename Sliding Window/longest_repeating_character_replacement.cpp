#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 424. Longest Repeating Character Replacement
 * Link -> https://leetcode.com/problems/longest-repeating-character-replacement/description/
 * 
 * Logic:-
 * We used a map to store data of the string.
 * Then we also find the maximum value of the charmap.
 * The crux of this problem is window size - max value should always be less than k
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charmap;
        int l = 0;
        int ans = 0;
        int maxSize = INT_MIN;
        for(int r=0;r<s.size();r++) {
            charmap[s[r]]++;
            maxSize = max(maxSize, charmap[s[r]]);
            while((r-l+1) - maxSize > k) {
                charmap[s[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};