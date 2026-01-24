#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 739. Daily Temperatures
 * Link - https://leetcode.com/problems/daily-temperatures/description/
 * 
 * Logic:-
 * So we use a stack for this problem,
 * First we init res array to 0.
 * The stack will store pairs of temp and idx that are waiting for a warmer day.
 * Then we start iterating the array.
 * If the current temperature is higher than whats on top of the stack,
 * then we have found the warmer day for the stack top value.
 * Update the res value accordingly
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        stack<pair<int,int>> stk;
        for(int i=0;i<arr.size();i++){
            int t = arr[i];
            while(!stk.empty() && t > stk.top().first) {
                auto pairMap = stk.top();
                stk.pop();
                res[pairMap.second] = i - pairMap.second;
            }
            stk.push({t, i});
        }
        return res;
    }
};
