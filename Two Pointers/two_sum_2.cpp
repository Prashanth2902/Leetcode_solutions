#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 167. Two Sum II - Input Array Is Sorted
 * Link -> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * 
 * Logic:-
 * Standard two pointers impl
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while(l < r){
            if(arr[l] + arr[r] == target) {
                return {l+1, r+1};
            } else if(arr[l] + arr[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return {-1, -1};
    }
};