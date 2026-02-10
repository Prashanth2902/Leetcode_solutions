#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 541. Reverse String II
 * Link -> https://leetcode.com/problems/reverse-string-ii/description/
 * 
 * Logic:-
 * Overengineered soln
 */

class Solution {
public:

    string reversePart(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseStr(string s, int k) {
        string res = "";
        int n = s.size();
        int i=0;
        bool flag = false;
        while((i+k) < s.size()) {
            if(!flag) {
                res += reversePart(s.substr(i, k));
                n -= k;
                i += k;
                flag = true;
            } else {
                res += s.substr(i, k);
                n -= k;
                i += k;
                flag = false;
            }

        }
        if(n < k) {
            if(!flag) {
                res += reversePart(s.substr(i, n));
            } else {
                res += s.substr(i, n);
            }
        } else {
            if(!flag) {
                res += reversePart(s.substr(i, k));
            } else {
                res += s.substr(i, k);
            }  
        }
        
        return res;
    }
};