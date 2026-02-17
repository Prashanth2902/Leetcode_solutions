#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 743. Network Delay Time
 * Link -> https://leetcode.com/problems/network-delay-time/description/
 * 
 * Logic:-
 * This is standard Dijkstra Impl.
 * K is the starting node. shortest map has the distance from k to nth node.
 * return the max value from shortest if all nodes are present, else -1
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto edge: times) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }
        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        minheap.push({0, k});
        while(!minheap.empty()) {
            auto curr = minheap.top();
            minheap.pop();
            int w1 = curr.first, n1 = curr.second;
            if(shortest.count(n1)) continue;
            shortest[n1] = w1;
            for(auto edge: adj[n1]) {
                int n2 = edge.first, w2 = edge.second;
                if(!shortest.count(n2)) {
                    minheap.push({w1+w2, n2});
                }
            }
        }
        int res = INT_MIN;
        for(int i=1;i<=n;i++) {
            if(!shortest.count(i)) return -1;
            res = max(res, shortest[i]);
        }
        return res;
    }
};
