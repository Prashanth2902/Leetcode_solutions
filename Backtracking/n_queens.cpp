#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard.
 * Problem - 51. N-Queens
 * Link -> https://leetcode.com/problems/n-queens/description/
 * 
 * Logic:-
 * So we have to find the apt positions for the Queens to be on the board
 * code is self explanatory
 */

class Solution {
public:

    bool isSafe(int r, int c, vector<string>& board) {
        for(int i = r-1; i >= 0; i--) {
            if(board[i][c] == 'Q') return false;
        }
        for(int i = r-1, j = c-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = r-1, j = c+1; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void dfs(int r, vector<string>& board, vector<vector<string>>& res) {
        if(r == board.size()) {
            res.push_back(board);
            return;
        }
        for(int c = 0; c < board.size(); c++) {
            if(isSafe(r, c, board)) {
                board[r][c] = 'Q';
                dfs(r+1, board, res);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, res);
        return res;
    }
};
