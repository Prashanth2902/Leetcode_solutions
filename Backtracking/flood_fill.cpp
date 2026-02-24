#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 733. Flood Fill
 * Link -> https://leetcode.com/problems/flood-fill/description/
 * 
 * Logic:-
 * standard flood fill impl
 */

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int dest, int src) {
        int rows = image.size();
        int cols = image[0].size();
        if(min(sr, sc) < 0 || sr == rows || sc == cols) return;
        if(image[sr][sc] != src) return;
        image[sr][sc] = dest;
        dfs(image, sr+1, sc, dest, src);
        dfs(image, sr-1, sc, dest, src);
        dfs(image, sr, sc+1, dest, src);
        dfs(image, sr, sc-1, dest, src);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorChange = image[sr][sc];
        if(color != colorChange) {
            dfs(image, sr, sc, color, colorChange);
        }
        return image;
    }
};