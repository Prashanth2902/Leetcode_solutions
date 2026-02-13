#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 2130. Maximum Twin Sum of a Linked List
 * Link -> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 * 
 * Logic:-
 * So we essentially first find the midpoint.
 * Then we reverse the second half of the list.
 * Then add the 1st values of the two linked lists.
 * Keep moving to the next till nullptr.
 * Return max value
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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nextNode = nullptr;
        ListNode* prev = nullptr;
        while(slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        int ans = 0;
        ListNode* start = head;
        while(prev) {
            ans = max(ans, start->val + prev->val);
            prev = prev->next;
            start = start->next;
        }
        return ans;
    }
};