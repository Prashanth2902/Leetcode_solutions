#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 25. Reverse Nodes in k-Group
 * Link -> https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 * 
 * Logic:-
 * So there is a bit of recursion involved in this problem.
 * First we go to the kth node.
 * Then we do reversal from kth node to the first node.
 * After this we do the same from k+1th node to 2k node till we reach list end
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int group = 0;
        while(curr && group < k) {
            group++;
            curr = curr->next;
        }

        if(group == k) {
            curr = reverseKGroup(curr, k);
            while(group-- > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }

        return head;
    }
};
