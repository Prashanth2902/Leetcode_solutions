#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 450. Delete Node in a BST
 * Link -> https://leetcode.com/problems/delete-node-in-a-bst/description/?q=delete+node+in+BST
 *
 * Logic:-
 * First we need to find the correct location of the node.
 * Once we find the node. if either of the sub children are there, return those.
 * If both are present, then find the next inorder value and make that as next node
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* minNode = root->right;
            while(minNode->left) {
                minNode = minNode->left;
            }
            root->val = minNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};