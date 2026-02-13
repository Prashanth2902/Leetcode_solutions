#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 98. Validate Binary Search Tree
 * Link -> https://leetcode.com/problems/validate-binary-search-tree/description/?q=valid+binary+search
 * 
 * Logic:-
 * Keep min max vals for dfs.
 * Left node has to be less than root and right node has to be more than root.
 * Keep iterating till you reach bottom
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

    bool dfs(TreeNode* root, int l, int r) {
        if(!root) return true;
        if(!(l < root->val && root->val < r)) return false;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, -2147483649LL, 2147483648LL);
    }
};