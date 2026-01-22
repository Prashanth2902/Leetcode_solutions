#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 124. Binary Tree Maximum Path Sum
 * Link -> https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?q=binary+tree+maximum+path
 * 
 * Logic:-
 * We have to calculate the maximum possible path in the tree.
 * There are two ways to do this after adding the dfs logic.
 * First we have to see if the arch causes the sum to increase
 * else there is also just one side that has the maximum path.
 * Both of these need to be computed.
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

    int dfs(TreeNode* root, int& currSum) {
        if(!root) return 0;
        int leftMax = max(dfs(root->left, currSum), 0);
        int rightMax = max(dfs(root->right, currSum), 0);
        currSum = max(currSum, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int currSum = root->val;
        dfs(root, currSum);
        return currSum;
    }
};