#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 358. Rearrange String k Distance Apart
 * Link -> https://leetcode.com/problems/rearrange-string-k-distance-apart/description/?envType=weekly-question&envId=2026-02-22
 * 
 * Logic:-
 * So this is a standard maxheap problem.
 * We also need to use a queue to track the next character.
 * First calculate the freq of each character and add it to the maxheap.
 * 
 * Also start adding the characters to the res after popping from maxheap.
 * Since the characters need to be at least k distance apart,
 * you need a queue system to track the characters.
 * Move the queue accordingly when the size is k.
 * Add the value back to the maxheap if the size is still more than 0.
 * 
 * If the res string size less than given string, the answer is "".
 * Else its the correct answer
 */

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;
        unordered_map<char, int> freq;
        for(auto c: s) freq[c]++;
        priority_queue<pair<int, char>> maxheap;
        for(auto i: freq) {
            maxheap.push({i.second, i.first});
        }
        queue<pair<int, char>> q;
        string res = "";

        while(!maxheap.empty()) {
            auto [f, c] = maxheap.top(); maxheap.pop();
            res += c;
            q.push({f-1, c});
            if(q.size() == k) {
                auto [f2, c2] = q.front(); q.pop();
                if(f2 > 0) maxheap.push({f2, c2});
            }
        }

        if(res.size() < s.size()) return "";
        else return res;
    }
};