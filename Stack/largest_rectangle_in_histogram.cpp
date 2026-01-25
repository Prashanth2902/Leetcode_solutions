#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 84. Largest Rectangle in Histogram
 * Link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 * 
 * Logic:-
 * The logic is to treat every bar as the potential shortest bar of a rectangle 
 * and find out how far it can expand left and right.
 * 
 * We use a monotonic increasing stack to track indices
 * when we see a bar shorter than the top of the stack, 
 * it means the "right wall" for the bar at the top has been found. 
 * We then pop it, use the current index as the right boundary 
 * and the new stack top as the left boundary to calculate the area before moving on.
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, h*w);
            }
            stk.push(i);
        }
        return ans;
    }
};