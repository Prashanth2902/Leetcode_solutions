#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 239. Sliding Window Maximum
 * Link -> https://leetcode.com/problems/sliding-window-maximum/description/
 * 
 * Logic:-
 * We use a deque to maintain the window. It takes in the index value
 * The first element of the deque always has the largest element
 * 
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            if(!deq.empty() && deq.front() == i - k) {
                deq.pop_front();
            }
            while(!deq.empty() && nums[deq.back()] < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};