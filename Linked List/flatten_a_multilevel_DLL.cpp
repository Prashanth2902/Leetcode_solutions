#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 430. Flatten a Multilevel Doubly Linked List
 * Link -> https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 * 
 * Logic:-
 * We use DFS to compute the entire tree.
 * We track two nodes, prev being the one that is processed and 
 * curr being the one that is going to be processed.
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


class Solution {
public:

    Node* dfs(Node* prev, Node* curr) {
        if(!curr) return prev;
        curr->prev = prev;
        prev->next = curr;

        Node* tempNext = curr->next;
        Node* tail = dfs(curr, curr->child);
        curr->child = nullptr;
        return dfs(tail, tempNext);
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        Node* fakehead = new Node(0, nullptr, head, nullptr);
        dfs(fakehead, head);
        fakehead->next->prev = nullptr;
        return fakehead->next;
    }
};