#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1762. Buildings With an Ocean View
 * Link -> https://leetcode.com/problems/buildings-with-an-ocean-view/description/
 * 
 * Logic:-
 * Start iterating from right side.
 * Track the maxVal so far.
 * If current height is more than maxVal, then it can see the ocean.
 * Add the index to result.
 * Reverse the result since we starting from the right
 */

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> res;
        int maxHeight = 0;
        for(int i=n-1;i>=0;i--) {
            if(maxHeight < heights[i]) {
                maxHeight = heights[i];
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};