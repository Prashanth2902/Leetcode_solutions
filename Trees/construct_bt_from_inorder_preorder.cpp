#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?q=construct+binary+tree
 * 
 * Logic:-
 * We first construct the inorder map to retrieve the position easily.
 * Then we find the root by using preIdx which is initialized to 0.
 * In preorder, the root always comes first, thats why its initialized to 0.
 * Then we do standard dfs and then do divide and conquer to build the full tree.
 */


  //Definition for a binary tree node.
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

    TreeNode* dfs(int& preIdx, vector<int>& preorder, unordered_map<int, int>& inordermap, int l, int r) {
        if(l > r) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inordermap[rootVal];
        root->left = dfs(preIdx, preorder, inordermap, l, mid-1);
        root->right = dfs(preIdx, preorder, inordermap, mid+1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inordermap;
        int n = preorder.size();
        for(int i=0;i<n; i++){
            inordermap[inorder[i]] = i;
        }
        int preIdx = 0;
        return dfs(preIdx, preorder, inordermap, 0, n-1);
    }
};