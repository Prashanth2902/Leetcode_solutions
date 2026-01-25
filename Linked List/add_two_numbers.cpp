#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 2. Add Two Numbers
 * Link - https://leetcode.com/problems/add-two-numbers/description/
 * 
 * Logic:-
 * Simple linked list traversal. Think of it as normal addition with carry
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry != 0) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int val = v1 + v2 + carry;

            carry = val / 10;
            val = val % 10;

            curr->next = new ListNode(val);
            curr = curr->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};