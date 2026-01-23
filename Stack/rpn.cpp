#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 150. Evaluate Reverse Polish Notation
 * Link -> https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=problem-list-v2&envId=plakya4j
 * 
 * Logic:-
 * Standard Simple stack impl
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s: tokens) {
            if(s == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a+b);
            } else if(s == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b-a);
            } else if(s == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a*b);
            } else if(s == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b/a);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
