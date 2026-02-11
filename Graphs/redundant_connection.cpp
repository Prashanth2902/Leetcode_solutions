#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 684. Redundant Connection
 * Link -> https://leetcode.com/problems/redundant-connection/description/
 * 
 * Logic:-
 * We essentially construct the graph from scratch with the given indices.
 * If we cannot construct, it means this connection already exists. 
 */

class DSU {
public:
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(parent[rootX] != parent[rootY]) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n);

        for(auto edge: edges) {
            if(!dsu->unite(edge[0], edge[1])) {
                return vector<int>{edge[0], edge[1]};
            }
        }
        return {};
    }
};
