#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 853. Car Fleet
 * Link - https://leetcode.com/problems/car-fleet/description/
 * 
 * Logic:-
 * We have to calculate the number of car fleets that will be present in the destination.
 * we first have to calculate the time it takes to reach the destination for each car.
 * If the stack is empty or if the car takes more time than the fleet ahead, 
 * we push the value to stack.
 * The size of the stack is the answer
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<speed.size();i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        stack<double> stk;
        for(auto car: cars) {
            double time = (double) (target - car.first)/car.second;
            if(stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return stk.size();
    }
};