#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 230. Kth Smallest Element in a BST
 * Link -> https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?q=kth+smallest
 * 
 * Logic:-
 * Do normal inorder and store in array.
 * Get the kth element from start
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

    void dfs(TreeNode* root, int k, vector<int>& arr) {
        if(!root) return;
        dfs(root->left, k, arr);
        arr.push_back(root->val);
        dfs(root->right, k, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, k, arr);
        return arr[k-1];
    }
};