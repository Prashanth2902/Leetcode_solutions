#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 287. Find the Duplicate Number
 * Link - https://leetcode.com/problems/find-the-duplicate-number/description/?q=find+the+duplicate+number
 * 
 * Logic:-
 * We use the fast and slow pointers logic to find the cycle.
 * Then we use another pointer to find the entrance of the cycle
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int slow2 = 0;
        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2) return slow;
        }
    }
};