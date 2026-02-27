#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 55. Jump Game
 * Link -> https://leetcode.com/problems/jump-game/description/
 * 
 * Logic:-
 * This is a DP type problem.
 * We need to see if we can reach the last index.
 * the end is either the min of size of num or max jump len from that postion.
 * Then iterate from j is i+1 to end.
 * If any one is correct. Return true
 * Else return false
 */

class Solution {
public:

    bool dfs(int i, vector<int>& nums, vector<int>& cache) {
        if(i == nums.size() - 1) return true;
        if(cache[i] != -1) return cache[i];
        int end = min((int)nums.size(), i + nums[i] + 1);
        for(int j=i+1;j<end;j++) {
            if(dfs(j, nums, cache)) {
                cache[i] = true;
                return true;
            }
        }
        cache[i] = false;
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        return dfs(0, nums, cache);
    }
};