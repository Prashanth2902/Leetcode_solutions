#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium.
 * Problem - 238. Product of Arrays Except Self
 * Link -> https://leetcode.com/problems/product-of-array-except-self/description/?q=product+of+array+except+self
 * 
 * Logic:-
 * This is a classic prefix and suffix multiplication problem.
 * Initially we compute the suffix of an array index with its previous value * array value.
 * We then compute the prefix of an array index with its next value * array value.
 * Our final result will be the multiplication of prefix[idx] and suffix[idx]
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, 1);
        vector<int> pre(n, 1);
        pre[0] = 1;
        suf[n-1] = 1;
        for(int i=1;i<n;i++) {
            pre[i] = nums[i-1] * pre[i-1];
        }
        for(int i=n-2;i>=0;i--) {
            suf[i] = nums[i+1]*suf[i+1]; 
        }
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i] = suf[i]* pre[i];
        }
        return res;
    }
};