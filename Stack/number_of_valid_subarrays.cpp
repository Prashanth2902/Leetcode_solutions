#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 1063. Number of Valid Subarrays
 * Link -> https://leetcode.com/problems/number-of-valid-subarrays/description/
 * 
 * Logic:-
 * A subarray is valid if the leftmost element is not larger than other elements.
 * So what we do it use a stack to maintain this property.
 * If the top value idx of nums is bigger than next value, then we keep popping the answer.
 * the size of the stack is the number of subarrays that are all valid.
 */

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> stk;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            while(!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            stk.push(i);
            ans += stk.size();
        }
        return ans;
    }
};