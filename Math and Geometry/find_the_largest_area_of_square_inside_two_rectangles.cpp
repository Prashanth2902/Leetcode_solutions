#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3047. Find the Largest Area of Square Inside Two Rectangles
 * Link -> https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/
 * 
 * Logic:-
 * This problem sounds tough but its actually simple.
 * Essentially, we need to compare two adjacent rectangles.
 * We try to find the 4 sides of the inner rectangle.
 * 1) left side will be the max of left side.
 * 2) bottom side will be the max of the bottom side
 * 3) top will be the min of the top side
 * 4) right will be the min of right side
 * Then find the difference between x and y.
 * The smallest value between x and y will form a square.
 * Return max value of squares of adjacent rectangles
 */

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long fx = max(bl[i][0], bl[j][0]); // first
                long long fy = max(bl[i][1], bl[j][1]);
                long long sx = min(tr[i][0], tr[j][0]); // second
                long long sy = min(tr[i][1], tr[j][1]);

                long long dx = sx-fx;
                long long dy = sy-fy;
                if(dx > 0 && dy > 0) {
                    long long side = min(dx,dy);
                    ans = max(ans, side*side);
                }
            }
        }
        return ans;
    }
};