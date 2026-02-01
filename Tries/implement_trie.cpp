#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 208. Implement Trie (Prefix Tree)
 * Link -> https://leetcode.com/problems/implement-trie-prefix-tree/description/
 * 
 * Logic:-
 * Trie Impl
 */

class Node {
public:
    Node* arr[26];
    bool isWordEnd;
    Node() {
        for(int i=0;i<26;i++) arr[i] = nullptr;
        isWordEnd = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char s: word) {
            int i = s - 'a';
            if(curr->arr[i] == nullptr) {
                curr->arr[i] = new Node();
            }
            curr = curr->arr[i];
        }
        curr->isWordEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char s: word) {
            int i = s - 'a';
            if(curr->arr[i] == nullptr) {
                return false;
            }
            curr = curr->arr[i];
        }
        return curr->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char s: prefix) {
            int i = s - 'a';
            if(curr->arr[i] == nullptr) {
                return false;
            }
            curr = curr->arr[i];
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */