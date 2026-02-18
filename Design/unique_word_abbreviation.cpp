#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 288. Unique Word Abbreviation
 * Link -> https://leetcode.com/problems/unique-word-abbreviation/description/
 */

class ValidWordAbbr {
private:

    unordered_map<string, unordered_set<string>> data;

    string getAbbr(string s) {
        if(s.size() < 3) return s;
        return s[0] + to_string(s.size()-2) + s[s.size() - 1];
    }

public:

    ValidWordAbbr(vector<string>& dictionary) {
        for(string s: dictionary) {
            data[getAbbr(s)].insert(s);
        }
    }
    
    bool isUnique(string word) {
        if(!data.count(getAbbr(word))) {
            return true;
        }
        auto wordList = data[getAbbr(word)];
        if(wordList.count(word) && wordList.size() == 1) return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */