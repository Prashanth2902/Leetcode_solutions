#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 106. Construct Binary Tree from Inorder and Postorder Traversal
 * Link -> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 * 
 * Logic:-
 * We first construct the inorder map to retrieve the position easily.
 * Then we find the root by using postIdx which is initialized to inorder.size()-1.
 * In postorder, the root always comes last, thats why its initialized to inorder.size()-1.
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

    TreeNode* dfs(int& postIdx, unordered_map<int, int>& inordermap, vector<int>& postorder, int l, int r) {
        if(l > r) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inordermap[rootVal];
        root->right = dfs(postIdx, inordermap, postorder, mid+1, r);
        root->left = dfs(postIdx, inordermap, postorder, l, mid-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inordermap;
        int n = inorder.size();
        for(int i=0;i<n;i++) {
            inordermap[inorder[i]] = i;
        }
        int postIdx = n-1;
        return dfs(postIdx, inordermap, postorder, 0, n-1);
    }
};