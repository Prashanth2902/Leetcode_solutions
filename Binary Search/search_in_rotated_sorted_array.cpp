#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 33. Search in rotated sorted array
 * Link -> https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * 
 * Logic:-
 * This is a binary search problem that gets tricky very soon.
 * Since the array is rotated, we need to think of it as two sorted arrays combined into one.
 * If the middle value is greater than the left index, 
 * we then have to check if target is in range of the index. 
 * If it is in range then we update the right index. else left.
 * Similarly, if the middle value is less than the right index, 
 * then right portion of the array is sorted.
 * we again check if the target is in range of the index.
 * If it is in range then we update the left index. else right.
 * */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) {
                return m;
            } else {
                if(nums[l] <= nums[m]) {
                    if(target < nums[m] && target >= nums[l]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if(nums[r] >= target && target > nums[m]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }
        return -1;
    }
};