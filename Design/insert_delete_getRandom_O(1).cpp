#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 380. Insert Delete GetRandom O(1)
 * Link -> https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 */

class RandomizedSet {
public:
    unordered_map<int, int> valToIdx;
    vector<int> nums;

    RandomizedSet() {}

    bool insert(int val) {
        if (valToIdx.count(val))
            return false;
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!valToIdx.count(val))
            return false;

        int indexToRemove = valToIdx[val];
        int lastElement = nums.back();

        nums[indexToRemove] = lastElement;

        valToIdx[lastElement] = indexToRemove;

        nums.pop_back();
        valToIdx.erase(val);

        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */