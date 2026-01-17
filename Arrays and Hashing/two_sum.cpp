#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 1. Two Sum
 * Link -> https://leetcode.com/problems/two-sum/description/
 * 
 * Logic:-
 * We have to find the indices of two numbers that add up to the target.
 * This can be easily done with the hashmap.
 * We iterate over the array.
 * If we come across the difference between the array[index] and target in the hashmap,
 * we then return the answer.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++) {
            int diff = target - nums[i];
            if(m.find(diff) != m.end()) {
                return {i, m[diff]};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};