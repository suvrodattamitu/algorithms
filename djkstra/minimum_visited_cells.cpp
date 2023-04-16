//https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

//got tle  for last 2 test cases
#include <bits/stdc++.h>
using namespace std;

#define len(x) ((int)x.size()) 

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = len(grid), m = len(grid[0]);
        
        priority_queue<pair<int, pair<int, int>>>pq;
        pq.push({-1, {0, 0}});
        
        vector< vector<int> >temp (n, vector<int> (m, 1e9));
        temp[0][0] = 0;
        while(!pq.empty()) {
            auto tp = pq.top();
            int d = -tp.first, x = tp.second.first, y = tp.second.second;
            pq.pop();
            
            if(x == n-1 && y == m-1) return d;
            
            for(int k = 1; k <= grid[x][y]; k++) {
                int i = x + k;
                int j = y + k;
                
                if(i >= n && j >= m) {
                    break;
                }
                
                if(i < n && temp[i][y] > 1 + d) {
                    temp[i][y] = 1 + d;
                    pq.push({-temp[i][y], {i, y}});
                }
                
                if(j < m && temp[x][j] > 1 + d) {
                    temp[x][j] = 1 + d;
                    pq.push({-temp[x][j], {x, j}});
                }
            }
            
        }
        
        return -1;
    }
};