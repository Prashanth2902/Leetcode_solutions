#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 212. Word Search II
 * Link -> https://leetcode.com/problems/word-search-ii/description/
 * 
 * Logic:-
 * Use a trie to populate the words.
 * Then do standard DFS to track each word
 * Also use a pointer for traversing the trie
 */

class Node {
public:
    Node* arr[26];
    string isWord;

    Node() {
        for(int i=0;i<26;i++) arr[i] = nullptr;
        isWord = "";
    }
};

class Solution {
public:
    Node* root;

    void insert(string word) {
        Node* curr = root;
        for(auto c: word) {
            int i = c - 'a';
            if(curr->arr[i] == nullptr) {
                curr->arr[i] = new Node();
            }
            curr = curr->arr[i];
        }
        curr->isWord = word;
    }

    void dfs(int r, int c, vector<vector<char>>& board, vector<string>& res, Node* root) {
        int rows = board.size();
        int cols = board[0].size();
        if(min(r,c) < 0 || r == rows || c == cols || board[r][c] == '#') return;
        char letter = board[r][c];
        int idx = letter - 'a';

        if(!root->arr[idx]) return;

        Node* nextNode = root->arr[idx];
        if(nextNode->isWord != "") {
            res.push_back(nextNode->isWord);
            nextNode->isWord = "";
        }

        board[r][c] = '#';
        dfs(r+1, c, board, res, nextNode);
        dfs(r-1, c, board, res, nextNode);
        dfs(r, c-1, board, res, nextNode);
        dfs(r, c+1, board, res, nextNode);
        board[r][c] = letter;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for(int i=0;i<words.size();i++) {
            insert(words[i]);
        }
        
        int rows = board.size();
        int cols = board[0].size();

        vector<string> res;
        
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++){
                dfs(r, c, board, res, root);
            }
        }

        return res;
    }
};