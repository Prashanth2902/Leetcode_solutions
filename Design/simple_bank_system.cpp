#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 2043. Simple Bank System
 * Link -> https://leetcode.com/problems/simple-bank-system/description/
 */

class Bank {
public:
    unordered_map<int, long long> bankData;

    Bank(vector<long long>& balance) {
        int i=1;
        for(auto b: balance) {
            bankData[i] = b;
            i++;
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(bankData.count(account1) && bankData.count(account2)) {
            long long account1Money = bankData[account1];
            long long account2Money = bankData[account2];
            if(account1Money < money) {
                return false;
            }
            bankData[account1] -= money;
            bankData[account2] += money;
            return true;
        } else {
            return false;
        } 
    }
    
    bool deposit(int account, long long money) {
        if(bankData.count(account)) {
            bankData[account] += money;
            return true;
        } else {
            return false;
        }
    }
    
    bool withdraw(int account, long long money) {
        if(bankData.count(account)) {
            long long accountMoney = bankData[account];
            if(accountMoney < money) {
                return false;
            }
            bankData[account] -= money;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */