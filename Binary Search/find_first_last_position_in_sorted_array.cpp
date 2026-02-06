#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 34. Find First and Last Position of Element in Sorted Array
 * Link -> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * 
 * Logic:-
 * So we have to find the leftmost and rightmost position of the array target.
 * We have to do binary search twice to find the respective values.
 * In the case of finding left most value, we store that index and reduce right value.
 * Same goes for vice versa. 
 */

class Solution {
public:

    int binSearch(vector<int>& nums, int target, bool isLeft) {
        int l = 0, r = nums.size() - 1;
        int res = -1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) {
                if(isLeft) {
                    res = m;
                    r = m - 1;
                } else {
                    res = m;
                    l = m + 1;
                }
            } else if(nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lIndex = binSearch(nums, target, true);
        int rIndex = binSearch(nums, target, false);
        return {lIndex, rIndex};
    }
};