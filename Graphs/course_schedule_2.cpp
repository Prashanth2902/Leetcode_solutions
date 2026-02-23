#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 210. Course Schedule II
 * Link -> https://leetcode.com/problems/course-schedule-ii/description/
 * 
 * Logic:-
 * Standard Topological Sort Impl
 */

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);

        for(auto p: prerequisites){
            indeg[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indeg[i] == 0) q.push(i);
        }

        int finish = 0;
        vector<int> res(n);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            res[n-finish-1] = node;
            finish++;
            for(auto nei: adj[node]) {
                indeg[nei]--;
                if(indeg[nei] == 0) q.push(nei);
            }
        }

        if(finish != n) return {};
        return res;

    }
};
