#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 3848. Check Digitorial Permutation
 * Link -> https://leetcode.com/problems/check-digitorial-permutation/description/
 * 
 * Logic:-
 * So the individual number's factorial when added up should be same as the number.
 * First we calculate the factorial for the numbers 0 to 9.
 * Then we calculate the summation of individual digits of the number,
 * We then check if the new number is the same as the original number.
 * This is checked by creating a freq vector and comparing if they
 * are the same 
 */

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10);
        fact[0] = 1;

        for(int i = 1; i < 10; i++){
            fact[i] = fact[i-1] * i;
        }

        int x = n;
        int ans = 0;

        while(x != 0){
            ans += fact[x % 10];
            x /= 10;
        }

        return method(ans, n);
    }

    bool method(int ans, int n){
        vector<int> c1(10,0), c2(10,0);

        while(ans != 0){
            c1[ans % 10]++;
            ans /= 10;
        }

        while(n != 0){
            c2[n % 10]++;
            n /= 10;
        }

        return c1 == c2;
    }
};