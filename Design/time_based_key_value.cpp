#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 981. Time Based Key-Value Store
 * Link - https://leetcode.com/problems/time-based-key-value-store/description/?q=time+based
 */

class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& values = m[key];
        int l = 0, r = values.size() - 1;
        string res = "";
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(values[mid].first <= timestamp) {
                res = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
