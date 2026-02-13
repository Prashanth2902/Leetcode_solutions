#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 142. Linked List Cycle II
 * Link -> https://leetcode.com/problems/linked-list-cycle-ii/description/
 * 
 * Logic:-
 * So this is a variation of 2 pointers technique.
 * What we have to do is first do fast and slow pointers.
 * If the intersect, it will be the length of the cycle.
 * Then start a new pointer from the head.
 * Move the new pointer and the slow pointer by 1.
 * The place where they intersect is the starting point of the cycle
 */

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) {
            return nullptr;
        }
        ListNode* slow2 = head;
        while(slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};