#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1653. Minimum Deletions to Make String Balanced
 * Link -> https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
 * 
 * Logic:-
 * The crux of the problem is 'b' should come after 'a.
 * So we keep pushing elements to the stack.
 * If the curr element is 'a' and the top element in stack is 'b',
 * we pop that 'b' and increment ans
 */

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stk;
        int deleteNums = 0;
        for(auto c: s) {
            if(!stk.empty() && stk.top() == 'b' && c == 'a') {
                stk.pop();
                deleteNums++;
            } else {
                stk.push(c);
            }
        }
        return deleteNums;
    }
};