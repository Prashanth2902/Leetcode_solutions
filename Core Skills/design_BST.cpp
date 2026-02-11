#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int key;
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Implementation for Binary Search Tree Map
class TreeMap {
private:
    TreeNode *root;

    TreeNode* findMin(TreeNode *node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* removeHelper(TreeNode *curr, int key) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (key > curr->key) {
            curr->right = removeHelper(curr->right, key);
        } else if (key < curr->key) {
            curr->left = removeHelper(curr->left, key);
        } else {
            if (curr->left == nullptr) {
                // Replace curr with right child
                return curr->right;
            } else if (curr->right == nullptr) {
                // Replace curr with left child
                return curr->left;
            } else {
                // Swap curr with inorder successor
                TreeNode *minNode = findMin(curr->right);
                curr->key = minNode->key;
                curr->val = minNode->val;
                curr->right = removeHelper(curr->right, minNode->key);
            }
        }
        return curr;
    }

    void inorderTraversal(TreeNode *root, vector<int> &result) {
        if (root != nullptr) {
            inorderTraversal(root->left, result);
            result.push_back(root->key);
            inorderTraversal(root->right, result);
        }
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode *newNode = new TreeNode(key, val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode *current = root;
        while (true) {
            if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else if (key > current->key) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            } else {
                current->val = val;
                return;
            }
        }
    }

    int get(int key) {
        TreeNode *current = root;
        while (current != nullptr) {
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return current->val;
            }
        }
        return -1;
    }

    int getMin() {
        TreeNode *current = findMin(root);
        return (current != nullptr) ? current->val : -1;
    }

    int getMax() {
        TreeNode *current = root;
        while (current != nullptr && current->right != nullptr) {
            current = current->right;
        }
        return (current != nullptr) ? current->val : -1;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    vector<int> getInorderKeys() {
        vector<int> result{};
        inorderTraversal(root, result);
        return result;
    }
};
