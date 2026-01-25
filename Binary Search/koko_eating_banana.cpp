#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 875. Koko Eating Bananas
 * Link - https://leetcode.com/problems/koko-eating-bananas/description/?q=koko+eating+bananas
 * 
 * Logic:-
 * So we have to find the minimum rate at which koko can eat all the bananas.
 * The min rate would be 1 and max rate would be maxval of piles.
 * So we try to calculate the total time to eat all bananas of the mid value.
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0];
        for(int i=0;i<piles.size();i++){
            r = max(r, piles[i]);
        }
        while(l < r) {
            int m = l + (r-l)/2;
            long long time = 0;
            for(int pile: piles) {
                time += ceil((double)pile/m);
            }
            if(time <= h) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};