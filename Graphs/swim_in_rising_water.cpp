#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 778. Swim in Rising Water
 * Link -> https://leetcode.com/problems/swim-in-rising-water/description/
 * 
 * Logic:-
 * Basically we have to find the shortest path from the top left corner
 * to the bottom right corner.
 * So we essentially do "BFS" till we reach the destination.
 */

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        minheap.push({grid[0][0], 0, 0});
        while(!minheap.empty()) {
            auto curr = minheap.top();
            minheap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if(r == c && c == n-1) return t;
            for(auto dir: dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if(min(nr,nc) < 0 || nr == n || nc == n || visit.count({nr, nc})) continue;
                visit.insert({nr, nc});
                minheap.push({max(t, grid[nr][nc]), nr, nc});
            }
        }
        return n*n;
    }
};
