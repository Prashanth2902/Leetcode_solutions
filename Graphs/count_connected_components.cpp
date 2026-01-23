#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 323. Number of Connected Components in an Undirected Graph
 * Link -> https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 * 
 * Logic:-
 * This is standard DSU. Code is self explanatory
 */

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int comp;

    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        comp = n;
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    int unite(int x, int y) {
        int tempX = find(x);
        int tempY = find(y);
        if(tempX == tempY) {
            return false;
        } else {
            comp--;
            if(rank[tempX] > rank[tempY]) {
                parent[tempY] = tempX;
            } else if(rank[tempX] < rank[tempY]) {
                parent[tempX] = tempY;
            } else {
                parent[tempX] = tempY;
                rank[tempY]++;
            }
            return true;
        }
    }

    int getComp() {
        return comp;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        for(auto edge: edges) {
            dsu->unite(edge[0], edge[1]);
        }
        return dsu->getComp();
    }
};