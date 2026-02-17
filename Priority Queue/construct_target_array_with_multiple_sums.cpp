#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 1354. Construct Target Array With Multiple Sums
 * Link -> https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
 * 
 * Logic:-
 * Reverse Approach: Work backward from the target array to $[1, 1, \dots, 1]$ by always reducing the largest element.
 * Max-Heap: Use a priority_queue to efficiently extract the maximum value ($O(\log n)$) at each step.
 * The "Rest" Sum: Calculate the sum of all other elements ($rest = totalSum - largest$) to determine what to subtract.
 * Modulo Optimization: Use largest % rest instead of repeated subtraction to avoid TLE, similar to the Euclidean Algorithm.
 * Edge Cases: Immediately return false if the largest is smaller than the rest or if the new value becomes $\le 0$.
 * Termination: If you successfully reduce the top of the heap to $1$, the entire array has been restored to $1$s.
 */

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        priority_queue<long long> maxheap;
        long long totalSum = 0;

        for(auto n: target) {
            maxheap.push(n);
            totalSum += n;
        }

        while(maxheap.top() > 1) {
            auto maxVal = maxheap.top();
            maxheap.pop();

            long long remSum = totalSum - maxVal;

            if(remSum <= 0 || maxVal <= remSum) return false;

            long long prevVal = 1;
            if(remSum != 1) {
                prevVal = maxVal % remSum;
            }

            if(prevVal == 0 || prevVal == maxVal) return false;
            maxheap.push(prevVal);
            totalSum = remSum + prevVal;
        }
        return true;
    }
};