#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 143. Reorder List
 * Link -> https://leetcode.com/problems/reorder-list/description/?q=reorder+list
 * 
 * Logic:-
 * This problem is a combination of 3 sub problems :-
 * 1) Fast and slow pointers
 * 2) Reverse a list
 * 3) Merge two sorted lists
 * 
 */

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* first = head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        second = prev;
        while(second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};