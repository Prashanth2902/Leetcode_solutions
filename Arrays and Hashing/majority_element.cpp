#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 169. Majority Element
 * Link -> https://leetcode.com/problems/majority-element/description/
 * 
 * Logic:-
 * Boyer-Moore voting algo
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for(auto n: nums) {
            if(count == 0) {
                candidate = n;
                count = 1;
            } else {
                if(candidate == n) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return candidate;
    } 
};