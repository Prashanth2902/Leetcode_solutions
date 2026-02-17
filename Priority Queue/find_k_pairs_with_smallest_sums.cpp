#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 373. Find K Pairs with Smallest Sums
 * Link -> https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 * 
 * Logic:-
 * So we need to keep a track of the sum as the target.
 * We also need to store the indexs for reference.
 * We use a minheap to find smallest values.
 * 
 * First populate the heap with one array.
 * Then from the second array onwards. Add it to the result.
 */

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> minheap;

        vector<vector<int>> res;
        
        for(int i=0;i<min((int)nums1.size(), k); i++) {
            minheap.push({nums1[i] + nums2[0], {i, 0}});
        }

        while(k-- > 0) {
            auto top = minheap.top();
            minheap.pop();
            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            if(j+1 < nums2.size()) {
                minheap.push({nums1[i] + nums2[j+1], {i, j+1}});
            }
        }
        
        return res;

    }
};