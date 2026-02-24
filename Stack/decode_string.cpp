#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 394. Decode String
 * Link -> https://leetcode.com/problems/decode-string/description/
 * 
 * Logic:-
 * This is a simulation problem with stack
 */

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(auto c: s) {
            if(c != ']') {
                stk.push(c);
            } else {
                string minires = "";
                while(stk.top() != '[') {
                    minires += stk.top(); stk.pop();
                }
                reverse(minires.begin(), minires.end());
                stk.pop();
                string numstr = "";
                while(!stk.empty() && isdigit(stk.top())) {
                    numstr += stk.top(); stk.pop();
                }
                reverse(numstr.begin(), numstr.end());
                int num = stoi(numstr);
                string finalStr = "";
                for(int i=0;i<num;i++) {
                    finalStr += minires;
                }
                for(auto c2: finalStr) stk.push(c2);
            }
        }

        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};