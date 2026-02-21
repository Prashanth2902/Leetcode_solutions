#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 279. Perfect Squares
 * Link -> https://leetcode.com/problems/perfect-squares/description/
 * 
 * Logic:-
 * This is also a BFS problem.
 * This essentially checks the shortest path to reach 0 from n
 * Again we need a queue that tracks the initial state n and no of steps 0.
 * 
 */

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        q.push({n, 0});
        
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        
        while (!q.empty()) {
            auto [rem, steps] = q.front();
            q.pop();
            
            if (rem == 0) return steps;
            
            for (int i = 1; i * i <= rem; i++) {
                int next = rem - i * i;
                if (next >= 0 && !visited[next]) {
                    if (next == 0) return steps + 1;
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};