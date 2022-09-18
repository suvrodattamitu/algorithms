//https://leetcode.com/problems/number-of-islands
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <string>
using namespace std;

#define vii vector<vector<char>>

class Solution {
public:
    // Initialize direction vectors
    int dRow[4] = { 0, 1, 0, -1 };
    int dCol[4] = { -1, 0, 1, 0 };
    bool vis[301][301];
    
    // boundary of the given matrix
    bool isValid(int row, int col, int Rows, int Columns)
    {
        // If cell is out of bounds
        if (row < 0 || col < 0
            || row >= Rows || col >= Columns)
            return false;

        // If the cell is already visited
        if (vis[row][col])
            return false;

        // Otherwise, it can be visited
        return true;
    }
    
    void dfs(int row, int col, vector<vector<char>>& grid, int rows, int columns) {
        if (!isValid(row, col, rows, columns) || grid[row][col] == '0') {
            return;
        }
        
        vis[row][col] = true;
        
        // Push all the adjacent cells
        for (int i = 0; i < 4; i++) {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            
            dfs(adjx, adjy, grid, rows, columns);
        }        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        
        memset(vis,0,sizeof(vis));
        
        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ++ans;
                    dfs(i, j, grid, rows, columns);
                }
            }
        }
        
        return ans;
    }
};

int main() {
    vector<vector<char>> grid
    {
        {"1","1","0","0","0"},
        {"1","1","0","0","0"},
        {"0","0","1","0","0"},
        {"0","0","0","1","1"}
    };
    Solution obj;
    int ans = obj.numIslands(grid);

    cout << ans << endl;
}