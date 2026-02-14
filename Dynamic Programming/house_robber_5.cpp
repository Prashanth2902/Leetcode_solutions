#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3840. House Robber V
 * Link -> https://leetcode.com/problems/house-robber-v/description/
 * 
 * Logic:-
 * This logic is similar to House Robber 1.
 * We have an extra constraint of the colors.
 * We have to skip the next house if it has the same color.
 * Skip logic is same.
 * Include logic is if the next iteration of colors is same, then do i+2.
 * else do i.
 * return max of skip and include
 */

class Solution {
public:
    long long dfs(int i, vector<pair<int, int>>& data, vector<long long>& cache) {
        if(i >= data.size()) return 0;
        if(cache[i] != -1) {
            return cache[i];
        }
        long long skip = dfs(i+1, data, cache);
        int next = i+1;
        bool flag = false;
        while(next < data.size() && data[i].second == data[next].second && !flag) {
            next++;
            flag = true;
        }
        long long include = data[i].first + dfs(next, data, cache);
        return cache[i] = max(skip, include);
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<pair<int, int>> data;
        for(int i=0;i<nums.size();i++) {
            data.push_back({nums[i], colors[i]});
        }
        vector<long long> cache(nums.size(), -1);
        return dfs(0, data, cache);
    }
};