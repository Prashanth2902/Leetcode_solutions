#include<bits/stdc++.h>
using namespace std;

/** 
 * Leetcode Medium
 * Problem Name = 128. Longest Consecutive Sequence
 * 
 * Logic:-
 * The problem asks us to find the longest consecutive sequence of an array. 
 * We need to first convert the array into a set. Then we start iterating through the set.
 * If the previous number does not exist, this is our start condition. From here we will
 * increment the number by till it doesnt exist. We will also keep a counter to track the longest
 * consecutive length. Longest length is the answer.*/ 


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int ans = 0;
        for(auto num: numset) {
            if(!numset.count(num-1)) {
                int longest = 0;
                while(numset.count(num++)) {
                    longest++;
                }
                ans = max(ans, longest);
            }
        }
        return ans;
    }
};