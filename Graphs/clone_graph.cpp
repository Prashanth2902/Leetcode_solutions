#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 133. Clone Graph
 * Link -> https://leetcode.com/problems/clone-graph/description/
 * 
 * Logic:-
 * The Node is represented as an adjacency list.
 * We also have a mapper of the old Node to the copy Node.
 * When we create a new node, we add it to the map.
 * Then we iterate the neighbours of the old node to become
 * neighbours of the new node.
 */


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if(!node) return nullptr;
        if(m.count(node)) return m[node];
        Node* copy = new Node(node->val);
        m[node] = copy;
        for(auto x: node->neighbors) {
            copy->neighbors.push_back(dfs(x, m));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }
};