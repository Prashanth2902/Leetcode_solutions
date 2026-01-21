#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 36. Valid Sudoku
 * Link -> https://leetcode.com/problems/valid-sudoku/description/
 * 
 * Logic:-
 * This problem is simple but you have to be careful with the pointers.
 * We will be using 3 hashmaps to check sudoku validity.
 * One for rows, One for cols and one for each of the 9 boxes.
 * 
 * The rows and column ones are straightforward
 * The box ones are the tricky ones in terms of pointers.
 * the squareKey is calculate by easily assigning the point to a pair which would be
 * in one of the 9 sub boxes.
 * For example, the point (3, 5) would be in the sub box 5 since 3//3 + 5//3 is (1,2) sub box (1-indexing) 
 * 
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                pair<int, int> squareKey = {r / 3, c / 3};

                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true;
    }
};