#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1514. Path with Maximum Probability
 * Link -> https://leetcode.com/problems/path-with-maximum-probability/description/
 * 
 * Logic:-
 * This is again a standard dijkstra impl.
 * Difference is since we find the max probability. We need to use a maxheap.
 */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for(int i=0;i<edges.size();i++) {
            int src = edges[i][0], dest = edges[i][1];
            double w = succProb[i];
            adj[src].push_back({dest, w});
            adj[dest].push_back({src, w});
        }
        unordered_map<int, double> shortest;
        priority_queue<pair<double, int>> maxheap;
        maxheap.push({1, start_node});
        while(!maxheap.empty()) {
            auto curr = maxheap.top();
            maxheap.pop();
            double w1 = curr.first;
            int n1 = curr.second;
            if(shortest.count(n1)) continue;
            shortest[n1] = w1;
            for(auto edge: adj[n1]) {
                int n2 = edge.first;
                double w2 = edge.second;
                if(!shortest.count(n2)) {
                    maxheap.push({w1*w2, n2});
                }
            }
        } 
        if(shortest.count(end_node)) {
            return shortest[end_node];
        } else {
            return 0;
        }
    }
};