#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 381. Insert Delete GetRandom O(1) - Duplicates allowed
 * Link -> https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 */

class RandomizedCollection {
public:

    unordered_map<int, unordered_set<int>> valToIdx;
    vector<int> arr;

    RandomizedCollection() {}
    
    bool insert(int val) {
        bool notPresent = valToIdx[val].empty();
        valToIdx[val].insert(arr.size());
        arr.push_back(val);
        return notPresent;
    }
    
    bool remove(int val) {
        if(valToIdx[val].empty()) return false;

        int removeIdx = *valToIdx[val].begin();
        valToIdx[val].erase(removeIdx);

        int lastElement = arr.back();
        int lastElementIdx = arr.size() - 1;

        if(removeIdx != lastElementIdx) {
            arr[removeIdx] = lastElement;
            valToIdx[lastElement].erase(lastElementIdx);
            valToIdx[lastElement].insert(removeIdx);
        }

        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */