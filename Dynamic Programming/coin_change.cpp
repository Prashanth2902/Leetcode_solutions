#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 322. Coin Change
 * Link -> https://leetcode.com/problems/coin-change/description/
 * 
 * Logic:-
 * So this is an interesting problem.
 * So we iterate the coins for the amount
 * The result is stored in the array if the amount can be reached.
 * The we do DFS and get the final value of the amount we are going to use
 */

class Solution {
public:

    int dfs(vector<int>& coins, int amount, vector<int>& cache) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(cache[amount] != -2) return cache[amount];
        int minCoins = INT_MAX;
        for(auto coin: coins) {
            int res = dfs(coins, amount - coin, cache);
            if(res != -1) {
                minCoins = min(minCoins, res + 1);
            }
        }
        return cache[amount] = minCoins == INT_MAX ? -1 : minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount+1, -2);
        return dfs(coins, amount, cache);
    }
};
