#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 752. Open the Lock
 * Link -> https://leetcode.com/problems/open-the-lock/description/
 * 
 * Logic:-
 * This is a standard BFS. Because we need to find the shortest path
 * We track the string and the number of times in a queue.
 * We also need to track visited elements in a set. Some elements are already present in deadeneds.
 * Then it becomes standard BFS
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            string currStr = curr.first;
            int t = curr.second;

            if(currStr == target) {
                return t;
            }

            for(int i=0;i<4;i++) {
                for(int diff : {1, -1}) {
                    string next = currStr;
                    next[i] = (next[i] - '0' + diff + 10) % 10 + '0';
                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, t+1});
                    }
                }
            }
        }
        return -1;
    }
};