#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 153. Find Minimum in rotated sorted array.
 * Link -> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/?q=find+minimum
 * 
 * Logic:-
 * This problem is a standard binary search problem with a twist.
 * Since its a rotated sorted array, it is essentially a combination of two sorted arrays.
 * First we find the mid point of the array.
 * 1) If the mid point of the array is bigger than the right pointer,
 *    Then the answer should be on the right.
 * 2) Else it will be on the left.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r-l)/2;
            if(nums[l] < nums[r]) {
                return nums[l];
            } else {
                if(nums[m] > nums[r]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
        }
        return nums[l];
    }
};