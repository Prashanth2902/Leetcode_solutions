#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 708. Insert into a Sorted Circular Linked List
 * Link -> https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/
 * 
 * Logic:-
 * So we know the list is sorted
 * We need to track a previous node and the current node.
 * The inserted value will go in between these nodes.
 * So we traverse the list accordingly to find the right spot
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        Node* prev = head;
        Node* next = head->next;
        bool found = false;
        do {
            if(prev->val <= insertVal && insertVal <= next->val) {
                found = true;
            } else if(prev->val > next->val) {
                if(insertVal >= prev->val || insertVal <= next->val) {
                    found = true;
                }
            }
            if(found) break;
            prev = next;
            next = next->next;
        } while(prev != head);

        prev->next = new Node(insertVal, next);
        return head;
    }
};