#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 244. Shortest Word Distance II
 * Link -> https://leetcode.com/problems/shortest-word-distance-ii/description/
 */

class WordDistance {
public:

    unordered_map<string, vector<int>> cache;

    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++) {
            cache[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> w1 = cache[word1];
        vector<int> w2 = cache[word2];
        int res = INT_MAX;
        for(int i=0;i<w1.size();i++) {
            for(int j=0;j<w2.size();j++) {
                res = min(res, abs(w1[i] - w2[j]));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */