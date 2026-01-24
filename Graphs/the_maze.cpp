#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 490. The Maze
 * Link - https://leetcode.com/problems/the-maze/description/?envType=weekly-question&envId=2026-01-08
 * 
 * Logic:-
 * So we are given the starting position of the ball.
 * We need to check if the ball goes to the end position.
 * The ball will move continously in one direction till it hits a wall
 * We use a boolean 2D array to mark visited end points
 */

class Solution {
public:

    bool dfs(vector<vector<int>>& maze, int r, int c, int dr, int dc, vector<vector<bool>>& visit) {
        int rows = maze.size();
        int cols = maze[0].size();
        if(visit[r][c]) return false;
        if(r == dr && c == dc) return true;
        visit[r][c] = true;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto dir: directions) {
            int dr1 = dir.first;
            int dc1 = dir.second;
            int nextR = r;
            int nextC = c;
            while(nextR + dr1 >= 0 && nextR + dr1 < rows && 
            nextC + dc1 >= 0 && nextC + dc1 < cols && 
            maze[nextR + dr1][nextC + dc1] == 0) {
                nextR += dr1;
                nextC += dc1;
            }
            if(dfs(maze, nextR, nextC, dr, dc, visit)){
                return true;
            }
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        return dfs(maze, start[0], start[1], destination[0], destination[1], visit);
    }
};