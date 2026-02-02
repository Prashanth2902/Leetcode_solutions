#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 362. Design Hit Counter
 * Link -> https://leetcode.com/problems/design-hit-counter/description/?envType=weekly-question&envId=2026-02-01
 * 
 * Logic:-
 * Use a deque to track the hits.
 * Clean the deque for every function call.
 * Ensure the front value is less than or equal to timestamp + 300
 */

class HitCounter {
public:

    deque<int> deq;

    HitCounter() {
        
    }

    void cleanup(int timestamp) {
        while(!deq.empty() && deq.front() <= timestamp - 300) {
            deq.pop_front();
        }
    }
    
    void hit(int timestamp) {
        deq.push_back(timestamp);
        cleanup(timestamp);
    }
    
    int getHits(int timestamp) {
        cleanup(timestamp);
        return deq.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */