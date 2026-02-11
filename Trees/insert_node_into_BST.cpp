#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 701. Insert into a Binary Search Tree
 * Link -> https://leetcode.com/problems/insert-into-a-binary-search-tree/description/?q=insert+in+a+BST
 * 
 * Logic:-
 * Code is self explanatory.
 * Keep traversing the tree till you reach a leaf node
 * then add new node
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }

        TreeNode* temp = root;
        while(root) {
            if(root->val <= val) {
                if(root->right != NULL) {
                    root = root->right;
                } else {
                    root->right = new TreeNode(val);
                    break;
                }
            } else {
                if(root->left != NULL) {
                    root = root->left;
                } else {
                    root->left = new TreeNode(val);
                    break;
                }
            }
        }
        return temp;
    }
};