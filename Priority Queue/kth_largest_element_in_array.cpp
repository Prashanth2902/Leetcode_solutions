#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 215. Kth Largest Element in an Array
 * Link -> https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 * 
 * Logic:-
 * Simple minheap impl
 */


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto n: nums) {
            minheap.push(n);
            if(minheap.size() > k) minheap.pop();
        }
        return minheap.top();
    }
};