#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 621. Task Scheduler
 * Link -> https://leetcode.com/problems/task-scheduler/description/
 * 
 * Logic:-
 * This is a greedy way of solving this problem.
 * So basically our bottleneck is the task that is most frequent.
 * First we need to compute the idle slots. That is calculated by the formula below.
 * Then for each of the lower frequency characters, we constantly "fill" the idleSlots
 * with the other characters.
 * At a time there can only be "maxf - 1" slots between two highest freq character.
 * 
 * If idle slots goes -ve, then it means that all idle slots will be filled.
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char t: tasks) {
            count[t - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxf = count[25];
        int idleSlots = (maxf - 1) * n;

        for(int i=24;i>=0;i--) {
            idleSlots -= min(maxf - 1, count[i]);
        }

        return max(0, idleSlots) + tasks.size();
    }
};
