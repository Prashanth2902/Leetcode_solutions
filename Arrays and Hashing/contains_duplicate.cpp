#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 217. Contains Duplicate.
 * Link -> https://leetcode.com/problems/contains-duplicate/description/
 * 
 * Logic:-
 * Standard HashMap soln. If exists in hashmap, return true, else false.
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n : nums) {
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;
    }
};