//https://leetcode.com/problems/max-area-of-island/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt, Rows, Columns;
    int X[4] = {0,1,0,-1};
    int Y[4] = {-1,0,1,0};
    bool vis[55][55];

    // boundary of the given matrix
    bool isValid(int row, int col) {
        // If cell is out of bounds
        if (row < 0 || col < 0 || row >= Rows || col >= Columns)
            return false;

        // If the cell is already visited
        if (vis[row][col])
            return false;

        // Otherwise, it can be visited
        return true;
    }

    void dfs(int row, int col, vector<vector<int>>& grid) {
        if (!isValid(row, col) || grid[row][col] == 0) {
            return;
        }

        ++cnt;
        vis[row][col] = true;
        
        for(int i = 0; i < 4; i++) {
            int x = row + X[i];
            int y = col + Y[i];

            dfs(x, y, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        Rows = grid.size();
        Columns = grid[0].size();
        
        memset(vis,0,sizeof(vis));
        
        int ans = 0;
        for(int i = 0; i < Rows; i++) {
            for(int j = 0; j < Columns; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid);
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
        }
        
        return ans;
    }
};