#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 261. Graph Valid Tree
 * Link -> https://leetcode.com/problems/graph-valid-tree/description/
 * 
 * Logic:-
 * A tree is valid if all the components are connected and are not cicular
 * We use a DSU to simulate that
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
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        for(auto edge: edges) {
            if(!dsu->unite(edge[0], edge[1])) return false;
        }
        return dsu->getComp() == 1;
    }
};