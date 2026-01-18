#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 211. Design Add and Search Words.
 * Link -> https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 * 
 * Logic :-
 * The Node data structure is a Trie (Prefix Tree). This is the requirement for this problem. 
 * It is the standard implementation.
 * 
 * When the WordDictionary Object is created, we need to initialize the root object to a new Node().
 * 
 * The addWord function is the standard logic of adding a word into the Trie.
 * 
 * The search function is the crux of this problem. We need to find words which may include '.' characters.
 * We need to treat the dot as any character.
 * This follows the standard dfs where we the Node position in the tree and the idx of the word changes.
 * The logic handling changes based on the character.
 * 1) If the character is not '.', then we go to the next iteration of the dfs 
 * (incrementing idx and going to next node)
 * 2) If the character is '.', then we find at least one instance where the next node is present 
 * (iterating across all characters)
 * 
 */

class Node {
public:
    Node* arr[26];
    bool isWordEnd;

    Node() {
        for(int i=0;i<26;i++) {
            arr[i] = nullptr;
        }
        isWordEnd = false;
    }
};

class WordDictionary {
private:

    bool dfs(int idx, Node* root, string word) {
        if(!root) return false;
        for(int i = idx; i < word.size(); i++) {
            int currIdx = word[i] - 'a';
            if(word[i] != '.') {
                return dfs(i+1, root->arr[currIdx], word);
            } else {
                for(int j = 0; j < 26; j++) {
                    if(dfs(i+1, root->arr[j], word)) return true;
                }
                return false;
            }
        }
        return root->isWordEnd;
    }

public:

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto c: word) {
            int idx = c - 'a';
            if(!curr->arr[idx]) {
                curr->arr[idx] = new Node();
            }
            curr = curr->arr[idx];
        }
        curr->isWordEnd = true;
    }
    


    bool search(string word) {
        Node* curr = root;
        return dfs(0, curr, word);
    }
};