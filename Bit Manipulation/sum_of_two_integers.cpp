#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 371. Sum of Two Integers
 * Link -> https://leetcode.com/problems/sum-of-two-integers/description/
 * 
 * Logic:-
 * Convert a and b to bits and then do schoolwise addition.
 * If only a or b has 1, then result should have 1 (XOR)
 * the carry is done if both has 1 and then gets shifted to the left.
 * Keep doing this till b becomes 0
 */

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a&b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
