#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3834. Merge Adjacent Equal Elements
 * Link -> https://leetcode.com/problems/merge-adjacent-equal-elements/
 * 
 * Logic:-
 * If you think about it, the expected behaviour is like a stack.
 * Treat is as such. 
 * A vector is essentially a stack.
 * If the top element (back()) equals, currNum, 
 * Pop the last element and mulitply currNum by 2.
 * Keep doing this till you reach the end of the array
 */

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> stk;
        for(auto n: nums) {
            long long currNum = n;
            while(!stk.empty() && stk.back() == currNum) {
                stk.pop_back();
                currNum *= 2;
            }
            stk.push_back(currNum);
        }
        return stk;
    }
};