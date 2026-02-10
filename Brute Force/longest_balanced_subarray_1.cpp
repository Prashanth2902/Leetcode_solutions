#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3719. Longest Balanced Subarray I
 * Link -> https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10
 * 
 * Logic:-
 * The constraints are small enough for brute force.
 * We can use set to track this soln.
 * One for even and one for odd.
 * 
 */

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int maxi=0;
        unordered_set<int>even,odd;
        for(int i=0;i<nums.size();i++){
            even.clear();
            odd.clear();
            for(int j=i;j<nums.size();j++){
                if((nums[j]&1)==0)even.insert(nums[j]);
                else odd.insert(nums[j]);
            if(even.size()==odd.size())maxi=max(maxi,j-i+1);
            }
            
        }
        return maxi;
    }
};