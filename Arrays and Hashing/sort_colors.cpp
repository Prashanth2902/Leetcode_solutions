#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 75. Sort Colors
 * Link -> https://leetcode.com/problems/sort-colors/description/
 * 
 * Logic:-
 * Count sort impl
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr(3,0);
        for(auto i: nums) {
            arr[i]++;
        }
        int idx = 0;
        for(int i=0;i<nums.size();i++) {
            while(arr[idx] == 0) idx++;
            nums[i] = idx;
            arr[idx]--;
            
        }
    }
};