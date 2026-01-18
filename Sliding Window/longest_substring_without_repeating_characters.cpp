#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3. Longest Substring Without Repeating Characters
 * Link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?q=longest+substring
 * 
 * Logic:-
 * This is simple sliding window problem. We use a hashset to track the characters.
 * While the right pointer moves forward, 
 * if there are no duplicates found in the hashset, the character is inserted into the hashset and length is recorded
 * If there is a duplicate, we then move the left pointer till there is no duplicate.
 * Return max length.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        unordered_set<char> charset;
        for(int r=0;r<s.size();r++) {
            while(charset.count(s[r])) {
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};