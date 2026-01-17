#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 347. Top K frequent elements.
 * Link -> https://leetcode.com/problems/top-k-frequent-elements/description/?q=top+K+frequent+elements
 * 
 * Logic:-
 * This is a simple use of the hashmap.
 * Initially we first store the frequency of each element in the hashmap.
 * Then we sort the hashmap according to the frequency in the decreasing order.
 * Then we just select the top k elements from this updated hashmap.
 * We use a vector of pairs to sort in descending order.
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto n: nums) {
            m[n]++;
        }
        vector<pair<int,int>> temp;
        for(auto x: m) {
            temp.push_back({x.second, x.first});
        }
        sort(temp.rbegin(), temp.rend());
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(temp[i].second);
        }
        return res;
    }
};