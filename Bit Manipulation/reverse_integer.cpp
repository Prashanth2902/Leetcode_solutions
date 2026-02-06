#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 7. Reverse Integer
 * Link -> https://leetcode.com/problems/reverse-integer/description/
 * 
 * Logic:-
 * We should not use long for this question.
 * Do normal integer reversal.
 * But inside the while check if r goest out of bounds by a factor of 10
 */

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while(x) {
            if(r > INT_MAX/10 || r < INT_MIN/10) return 0;
            r = r*10 + x%10;
            x /= 10;
        }
        return r;
    }
};