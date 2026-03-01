#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size();
    int cols = grid[0].size();
    if(min(r, c) < 0 || r == rows || c == cols || grid[r][c] == '#') return;
    grid[r][c] = '#';
    dfs(grid,r+1,c);
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r,c-1);
}

int f(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int res = 0;
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            if(grid[r][c] == '.') {
                res++;
                dfs(grid, r, c);
            }
        }
    }
    return res;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            cin >> grid[r][c];
        }
    }
    cout << f(grid) << endl;
    return 0;
}