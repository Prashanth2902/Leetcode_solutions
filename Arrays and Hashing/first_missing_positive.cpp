#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 41. First Missing Positive
 * Link -> https://leetcode.com/problems/first-missing-positive/description/
 * 
 * Logic:-
 * So basically we are moving the numbers to its respective index through this sorting technique.
 * The positive numbers would be at its respective index.
 * For ex: [3, 1, -4, 7] would become [1, -4, 3, 7] after iterations.
 * Then we iterate through this array to find the first number thats missing
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
        return n+1;
    }
};