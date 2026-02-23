#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1462. Course Schedule IV
 * Link -> https://leetcode.com/problems/course-schedule-iv/description/?q=course+schedule
 * 
 * Logic:-
 * This is a standard Floyd Warshall Algorithm impl.
 * So this problem needs to know the pre reqs of the courses.
 * a->c if a->b and b->c.
 * This makes the algorithm used intuitive
 */

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(n ,vector<bool>(n, false));
        vector<bool> res;
        for(auto pre: prerequisites){
            adj[pre[0]][pre[1]] = true;
        }
        for(int k=0;k<n;k++) {
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                }
            }
        }
        for(auto q: queries) {
            res.push_back(adj[q[0]][q[1]]);
        }
        return res;
    }
};