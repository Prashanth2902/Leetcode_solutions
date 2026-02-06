#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 56. Merge Intervals
 * Link -> https://leetcode.com/problems/merge-intervals/description/
 * 
 * Logic:-
 * First we have to sort the list.
 * Then we iterate the array.
 * If the last element of the res and the next interval merge,
 * then we change the last element of the res to the max of the
 * two values.
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto x: intervals) {
            int start = x[0];
            int end = x[1];
            int lastEnd = res.back()[1];
            if(start <= lastEnd) {
                res.back()[1] = max(end, lastEnd);
            } else {
                res.push_back({start, end});
            }
        }
        return res;
    }
};