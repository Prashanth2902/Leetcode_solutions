#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Easy
 * Problem - 170. Two Sum III - Data Structure Design
 * Link -> https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 */

class TwoSum {
public:

    vector<int> v;
    bool isSort = false;
    
    TwoSum() {
        
    }
    
    void add(int number) {
        v.push_back(number);
        isSort = false;
    }
    
    bool find(int value) {
        if(!isSort) {
            sort(v.begin(), v.end());
            isSort = true;
        }
        int l = 0, r = v.size() - 1;
        while(l < r) {
            if(v[l] + v[r] == value) {
                return true;
            } else if(v[l] + v[r] > value) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */