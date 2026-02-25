#include<bits/stdc++.h>
using namespace std;


/**
 * Leetcode Medium
 * Problem - 1008. Construct Binary Search Tree from Preorder Traversal
 * Link -> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 * 
 * Logic:-
 * We are given the preorder array.
 * The first element will always be the root of the tree.
 * Find the left and right elements of the tree in the array.
 * Recursively call for the left and right sub arrays
 */

 // Definition for a binary tree node.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> left, right;
        for(int i=1;i<preorder.size();i++) {
            if(preorder[i] > preorder[0]) right.push_back(preorder[i]);
            if(preorder[i] < preorder[0]) left.push_back(preorder[i]);
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};