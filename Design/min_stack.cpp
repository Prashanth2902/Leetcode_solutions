#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 155. Min Stack
 * Link -> https://leetcode.com/problems/min-stack/description/
 * 
 * Logic:-
 * Standard simple minStack impl.
 * The second value of the pair is the lowest value.
 */

class MinStack {
public:

    stack<pair<int,int>> stk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push({val, val});
        } else {
            int lowestVal = min(val, stk.top().second);
            stk.push({val, lowestVal});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */