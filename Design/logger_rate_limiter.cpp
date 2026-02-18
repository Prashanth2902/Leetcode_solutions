#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 359. Logger Rate Limiter
 * Link -> https://leetcode.com/problems/logger-rate-limiter/description/
 */

class Logger {
public:

    unordered_map<string, int> ok;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */