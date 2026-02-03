#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem -> 152. Maximum Product Subarray
 * Link -> https://leetcode.com/problems/maximum-product-subarray/
 * 
 * Logic:-
 * This is similar to kadane's algorithm but for products.
 * curmax variable is to find the maximum value so far.
 * curmin exists because a double negative product can become positive.
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curmin = 1, curmax = 1;

        for(auto n: nums) {
            int tmp = n * curmax;
            curmax = max(max(n*curmax, n*curmin), n);
            curmin = min(min(tmp, n*curmin), n);
            ans = max(ans, curmax);
        }
        
        return ans;
    }
};