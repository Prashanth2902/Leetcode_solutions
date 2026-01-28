#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 102. Binary Tree Level Order Traversal
 * Link -> https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * 
 * Logic:-
 * Standard BFS
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> subres;
            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();
                subres.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(subres);
        }
        return res;
    }
};