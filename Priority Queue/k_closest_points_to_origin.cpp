#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 973. K Closest Points to Origin
 * Link -> https://leetcode.com/problems/k-closest-points-to-origin/description/
 * 
 * Logic:-
 * We use a maxheap for this problem.
 * We first calculate this distance and then add that and its coords to the heap.
 * If the heap size exceeds k, we then have to pop the heap's top element.
 * Then the k closest points to origin will only remain in the heap
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> heap;
        for(int i=0;i<points.size();i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            heap.push({dist, {points[i][0], points[i][1]}});
            if(heap.size() > k) heap.pop();
        }
        vector<vector<int>> res;
        while(!heap.empty()) {
            res.push_back({heap.top().second.first, heap.top().second.second});
            heap.pop();
        }
        return res;
    }
};