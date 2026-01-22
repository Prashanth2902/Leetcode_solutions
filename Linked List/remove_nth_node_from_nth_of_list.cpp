#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 19. Remove Nth Node From End of List
 * Link -> https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * 
 * Logic:-
 * This is a one pass soln.
 * The code is self explanatory
 * We are using dummy node to handle only one element edge case
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* second = head;
        while(second && n>0){
            second = second->next;
            n--;
        }
        ListNode* first = dummy;
        while(second){
            first = first->next;
            second = second->next;
        }
        ListNode* temp = first->next;
        first->next = first->next->next;
        delete(temp);
        return dummy->next;
    }
};