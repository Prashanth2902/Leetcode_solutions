#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem name - 297. Serialize and Deserialize Binary Tree.
 * 
 * Logic:-
 * For the serialize function, we are given a tree and convert it to a string.
 * We do BFS to add the values to the string. If there is a nullptr, we add "N".
 * 
 * For the deserialize function, we have to construct a tree from the given string.
 * We use stringstream to convert the given data:string into a stream.
 * val will have the actual values that will be in the tree.
 * getline(ss, val, ',') gets each specific character separated by ',' in data. Value is stored in val.
 * Here we create another BFS logic to craft the tree from the root.
 * We do standard BFS till val is valid or queue in not empty. 
 */

 //Provided code
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) res += "N,";
            else {
                res += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if(val.empty()) return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(!getline(ss, val, ',')) break;
            if(val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            if(!getline(ss, val, ',')) break;
            if(val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));