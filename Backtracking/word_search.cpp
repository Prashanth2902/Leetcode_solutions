#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 79. Word Search
 * Link -> https://leetcode.com/problems/word-search/description/?q=word+search
 * 
 * Logic:-
 * This is standard backtracking along with visited in the same board.
 * We use the pointer i to indicate the word traversal
 * If i reaches the end of the word length, it means that the word is found
 */

class Solution {
public:

    bool dfs(int i, vector<vector<char>>& board, string word, int r, int c) {
        if(i == word.size()) return true;
        
        int rows = board.size();
        int cols = board[0].size();
        
        if(min(r,c) < 0 || r == rows || c == cols || board[r][c] == '#' || board[r][c] != word[i]) return false;

        char letter = board[r][c];
        board[r][c] = '#';

        bool result = dfs(i+1, board, word, r+1, c) ||
            dfs(i+1, board, word, r-1, c) ||
            dfs(i+1, board, word, r, c+1) ||
            dfs(i+1, board, word, r, c-1);
        
        board[r][c] = letter;
        return result;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(dfs(0, board, word, r, c)) return true;
            }
        }
        return false;
    }
};