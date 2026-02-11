#include<bits/stdc++.h>
using namespace std;

/**
 * You are given a binary matrix Grid where 0s represent land and 1s represent rocks that can not be traversed. 
 * Return the length of the shortest path from the top-left corner of Grid to the bottom-right corner such that 
 * all traversed cells are land cells. You may only move vertically or horizontally through land cells.
 */

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        unordered_set<string> visit;
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        visit.insert("0,0");

        int length = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cell = queue.front();
                queue.pop();
                int r = cell.first, c = cell.second;
                if (r == ROWS - 1 && c == COLS - 1) {
                    return length;
                }

                vector<vector<int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (vector<int>& neighbor : neighbors) {
                    int dr = neighbor[0], dc = neighbor[1];
                    if (min(r + dr, c + dc) < 0 ||
                        r + dr == ROWS || c + dc == COLS ||
                        visit.find(to_string(r + dr) + "," + to_string(c + dc)) != visit.end() || grid[r + dr][c + dc] == 1) {
                        continue;
                    }
                    queue.push({r + dr, c + dc});
                    visit.insert(to_string(r + dr) + "," + to_string(c + dc));
                }
            }
            length++;
        }
        return -1;
    }
};
