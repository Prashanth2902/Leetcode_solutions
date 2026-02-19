#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 11. Container With Most Water
 * Link -> https://leetcode.com/problems/container-with-most-water/description/
 * 
 * Logic:-
 * Code is pretty straighforward.
 * We only move the pointer that is shorter. Since that leads to less area.
 * We are trying to maximize area.
 */

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int ans = 0;
        while(l<r) {
            int height = min(heights[l], heights[r]);
            ans = max(ans, (r-l) * height);
            if(heights[l] > heights[r]) r--;
            else l++;
        }
        return ans;
    }
};