#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 978. Longest Turbulent Subarray
 * Link -> https://leetcode.com/problems/longest-turbulent-subarray/description/
 * 
 * Logic:-
 * We use a string prev to track the symbol change.
 * Then it becomes standard sliding window.
 * If sign is not consistently changed, then reset sign and l becomes r - 1.
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1, res = 1;
        string prev = "";
        while(r < arr.size()) {
            if(arr[r-1] > arr[r] && prev != ">") {
                res = max(res, (r-l+1));
                r++;
                prev = ">";
            } else if(arr[r-1] < arr[r] && prev != "<") {
                res = max(res, (r-l+1));
                r++;
                prev = "<";
            } else {
                r = (arr[r] == arr[r-1]) ? r + 1: r;
                l = r-1;
                prev = "";
            }
        }
        return res;
    }
};