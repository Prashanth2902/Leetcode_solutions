#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1448. Count Good Nodes in Binary Tree
 * Link -> https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
 * 
 * Logic:-
 * A node is a good node if its value is greater than or equal than the root.
 * We can implement this with BFS.
 * As we go down the level, if the current node is bigger than the root node, 
 * then its a good node. 
 * Return num of good noes
 */


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while(!q.empty()) {
            auto [node, maxval] = q.front();
            q.pop();
            
            if(node->val >= maxval) {
                res++;
            }

            if(node->left) {
                q.push({node->left, max(maxval, node->val)});
            }
            if(node->right) {
                q.push({node->right, max(maxval, node->val)});
            }
        }
        return res;
    }
};
