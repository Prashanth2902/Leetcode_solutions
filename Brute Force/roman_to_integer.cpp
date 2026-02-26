#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * Leetcode Easy
 * Problem - 13. Roman to Integer
 * Link -> https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=programming-skills
 * 
 * Logic:-
 * Roman String starts from highest to lowest.
 * So if we find a lower character before a higher character, we decrement the lower character.
 * Its usually the one
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};