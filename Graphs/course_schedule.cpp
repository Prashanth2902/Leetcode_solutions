#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 207. Course Schedule
 * Link -> https://leetcode.com/problems/course-schedule/description/
 * 
 * Logic:-
 * This problem tests if you can find cycles in a directed graph.
 * 
 * First we build the adjacency list.
 * Then we do a dfs for each course.
 * If any of them return false, it implies there is a cycle. So the answer would be false.
 * 
 * In the dfs, we are also tracking a set "visit" to know the current path of the dfs.
 * We are then clearing the adjacency list of the course to indicate its computation is complete.
 * It is mainly done to speed up the runtime.
 */

class Solution {
private:

    bool dfs(int i, unordered_map<int, vector<int>>& adj, unordered_set<int>& visit) {
        if(visit.count(i)) return false;
        if(adj[i].empty()) return true;
        visit.insert(i);
        
        for(auto x: adj[i]) {
            if(!dfs(x, adj, visit)) return false;
        }

        visit.erase(i);
        adj[i].clear();
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visit;
        for(int i=0;i<n;i++) {
            adj[i] = {};
        }
        for(auto a: arr) {
            adj[a[0]].push_back(a[1]);
        }
        for(int i=0;i<n;i++) {
            if(!dfs(i, adj, visit)) return false;
        }
        return true;
    }
};