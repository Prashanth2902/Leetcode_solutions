#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1244. Design A Leaderboard
 * Link - https://leetcode.com/problems/design-a-leaderboard/?envType=weekly-question&envId=2026-01-01
 * 
 * Logic:-
 * map impl for playerId to score mapping.
 * vector for calculating top K values.
 */

class Leaderboard {
public:

    unordered_map<int, int> lmap;
    vector<int> sumcalc;

    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(!lmap.count(playerId)) {
            lmap[playerId] = score;
            sumcalc.push_back(score);
        } else {
            int oldScore = lmap[playerId];
            reset(playerId);
            lmap[playerId] = score + oldScore;
            sumcalc.push_back(score + oldScore);
        }
    }
    
    int top(int K) {
        int sum = 0;
        sort(sumcalc.rbegin(), sumcalc.rend());
        for(int i=0;i<K;i++){
            sum += sumcalc[i];
        }
        return sum;
    }
    
    void reset(int playerId) {
        int remscore = lmap[playerId];
        lmap.erase(playerId);
        auto it = find(sumcalc.begin(), sumcalc.end(), remscore);
        if(it != sumcalc.end()) {
            sumcalc.erase(it);
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */