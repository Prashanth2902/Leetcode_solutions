#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 130. Surrounded Regions
 * Link -> https://leetcode.com/problems/surrounded-regions/description/
 * 
 * Logic:-
 * This follows a flood fill algorithm in DFS style.
 * So first we mark the border 'O' with 'S'
 * Then the we change it back to 'O' after doing it for all sides.
 * The inner 'O's will always become 'X' because it is always surrounded by
 * 'X's in all 4 sides
 */

class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        if(min(r,c) < 0 || r == rows || c == cols || board[r][c] != 'O') return;
        board[r][c] = 'S';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r=0; r<rows;r++) {
            dfs(board, r, 0);
            dfs(board, r, cols-1);
        }

        for(int c=0;c<cols;c++){
            dfs(board, 0, c);
            dfs(board, rows-1, c);
        }

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if(board[r][c] == 'S') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
