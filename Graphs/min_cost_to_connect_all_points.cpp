#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1584. Min Cost to Connect All Points
 * Link -> https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 * 
 * Logic:-
 * This is standard MST calculation.
 * First we calculate the distance between two points and form an adjacency list.
 * Then we do standard Prim's Impl
 */

typedef pair<int, int> pii;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pii>> adj;
        for(int i=0;i<n;i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        unordered_set<int> visit;
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        minheap.push({0, 0});
        int res = 0;
        while(!minheap.empty()) {
            auto [w1, n1] = minheap.top();
            minheap.pop();
            if(visit.count(n1)) continue;
            visit.insert(n1);
            res += w1;
            for(auto [w2, n2]: adj[n1]) {
                if(!visit.count(n2)) {
                    minheap.push({w2, n2});
                }
            }
        }
        return res;
    }
};
