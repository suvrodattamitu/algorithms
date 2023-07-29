//https://leetcode.com/problems/detect-cycles-in-2d-grid/description/
#include <bits/stdc++.h>
using namespace std;

/*
If there exists a cycle, then all the cells of the cycle should have the same value, 
and they should be connected 
and also the last and the first element should have different parents.
*/

class Solution {
public:
    bool IsVisited[501][501] = {false};
    bool flag = false;
    vector<pair<int , int>> moves = {{0,1} , {0,-1} , {1,0} , {-1,0}};
    void dfs(int x , int y , int par_x , int par_y , vector<vector<char>> &grid)
    {
        for(auto z : moves)
        {
            int x_new = x + z.first;
            int y_new = y + z.second;

            if(x_new < 0 || y_new < 0 || x_new >= grid.size() || y_new >= grid[0].size() || grid[x][y] != grid[x_new][y_new]) continue;
            
            if(par_x == x_new && par_y == y_new) continue;

            if(IsVisited[x_new][y_new]) {
                flag = true;
                return;
            }

            IsVisited[x_new][y_new] = true;
            dfs(x_new , y_new , x , y, grid);
        }

        return;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!IsVisited[i][j])
                {
                    IsVisited[i][j] = true;
                    dfs(i, j, -1, -1, grid);
                    if(flag) return true;
                }
            }
        }
        return flag;
    }
}