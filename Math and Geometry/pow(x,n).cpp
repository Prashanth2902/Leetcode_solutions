#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 50. Pow(x, n)
 * Link -> https://leetcode.com/problems/powx-n/description/
 * 
 * Logic:-
 * This is binary exponentiation
 * The first if condition essentially makes
 * x^-n to (1/x)^n. Its the same thing.
 * 
 * Then we keep multiplying x with 2
 */

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0) {
            exp = -exp;
            x = 1/x;
        }
        double res = 1;
        double cp = x;
        while(exp) {
            if(exp&1) res *= cp;
            cp *= cp;
            exp /= 2;
        }
        return res;
    }
};