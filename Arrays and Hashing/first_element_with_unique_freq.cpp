#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3843. First Element with Unique Frequency
 * Link -> https://leetcode.com/problems/first-element-with-unique-frequency/description/
 * 
 * Logic:-
 * 2 hashmaps are needed. 
 * 1 for frequency of characters
 * 1 for frequency of frequencies
 * Return the value that has only 1 frequncy of frequency
 */

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m, m1;

        for (int i : nums) {
            m[i]++;
        }

        for (auto i : m) {
            m1[i.second]++;
        }

        for (int i = 0; i < n; i++) {
            if (m1[m[nums[i]]] == 1)
                return nums[i];
        }

        return -1;
    }
};