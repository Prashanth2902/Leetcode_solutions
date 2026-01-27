#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 138. Copy List with Random Pointer
 * Link -> https://leetcode.com/problems/copy-list-with-random-pointer/
 * 
 * Logic:-
 * So this is a linked list with another random pointer.
 * What we have to do is create a map that maps th original list to the random list
 * Since we dont know what random would be pointing to, 
 * the map will give us the correct answer in this case
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:

    Node* dfs(Node* head, unordered_map<Node*, Node*>& copyMap) {
        if(!head) return nullptr;
        if(copyMap.count(head)) return copyMap[head];

        Node* copy = new Node(head->val);
        copyMap[head] = copy;
        copy->next = dfs(head->next, copyMap);
        copy->random = copyMap[head->random];
        return copy;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyMap;
        return dfs(head, copyMap);
    }
};