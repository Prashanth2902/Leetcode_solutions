#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 61. Rotate List
 * Link -> https://leetcode.com/problems/rotate-list/description/
 * 
 * Logic:-
 * First we need to make the list circular
 * This can be done by attaching the last node to the head.
 * Then we need to find the postion in which where the new tail would exist
 * After going to the position,
 * The next node after the new tail would be the new head
 * make the next pointer of new tail null
 */


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* oldTail = head;
        while(oldTail->next) {
            oldTail = oldTail->next;
            len++;
        }
        oldTail->next = head;
        ListNode* newTail = head;
        for(int i=0;i<len - (k%len) - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        head = newHead;
        return head;
    }
};