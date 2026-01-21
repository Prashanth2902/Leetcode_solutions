#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 42. Trapping Rain Water
 * Link -> https://leetcode.com/problems/trapping-rain-water/description/
 * 
 * Logic:-
 * This is a 2 pointer and prefix and suffix problem combined into one.
 * First we calculate the prefix and suffix array.
 * To calculate the prefix array. We take the max of current idx and prev idx.
 * to calculate the suffix array. We take the max of current idx and next idx.
 * Then the difference between the min of suffix and prefix to height of same idx is the answer
 * Compute for all indices
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        prefix[0] = height[0];
        suffix[n-1] = height[n-1];

        for(int i=1;i<n;i++) {
            prefix[i] = max(height[i], prefix[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = max(height[i], suffix[i+1]);
        }

        int res = 0;
        for(int i=0;i<n;i++){
            res += min(prefix[i], suffix[i]) - height[i];
        }
        
        return res;
    }
};