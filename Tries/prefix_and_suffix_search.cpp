#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 745. Prefix and Suffix Search
 * Link -> https://leetcode.com/problems/prefix-and-suffix-search/description/?source=submission-ac
 * 
 * Logic:-
 * So this is a trie question.
 * The main concept is we are given the prefix and suffix of the word, we need to find its index.
 * 
 * First we need a divider character. That is '{'. This is selected because it comes right after,
 * 'z' character. So we can just create an array of 27 characters.
 * 
 * Then we need to start storing the words into the prefix tree.
 * Let me give an example.
 * The word will be "dog".
 * "dog" will be stored as "g{dog, og{dog, dog{dog"
 * Index would also be stored in the trie. It is the index of the word in the array.
 * 
 * So when the f() function is called with suffix and prefix, we need to find the,
 * respective word in the trie and return the index.
 * 
 * For example, if dog is a word in the array, we insert all iterations of dog in trie
 * Then if f('d', 'g') is called, it will try to find 'g{d' in the trie
 */

class Node {
public:
    Node* arr[27];
    int idx;

    Node() {
        for(int i=0;i<27;i++) arr[i] = nullptr;
        idx = -1;
    }
};

class WordFilter {
private:
    Node* root;

    void insert(string word, int idx) {
        Node* curr = root;
        for(auto c: word) {
            int i = c - 'a';
            if(!curr->arr[i]){
                curr->arr[i] = new Node();
            }
            curr = curr->arr[i];
            curr->idx = idx;
        }
    }

public:

    WordFilter(vector<string>& words) {
        root = new Node();
        for(int i=0;i<words.size();i++) {
            string word = words[i];
            for(int j=0;j<word.size();j++) {
                string toInsert = word.substr(j) + '{' + word;
                insert(toInsert, i);
            }
        }
    }
    
    int f(string pref, string suff) {
        Node* curr = root;
        string searchstr = suff + '{' + pref;
        for(char c: searchstr) {
            int i = c - 'a';
            if(!curr->arr[i]) return -1;
            curr = curr->arr[i];
        }
        return curr->idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */