//https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/
#include <bits/stdc++.h>
using namespace std;

struct MergeBigger {
    std::vector<int> p;
    MergeBigger(int n) : p(n) { init(); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        int small = std::min(rx, ry), big = std::max(rx, ry);
        p[small] = big;
    }
    void init() {
        for (int i = 0; i < int(p.size()); i++) p[i] = i;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<MergeBigger> jump1(m, MergeBigger(n + 1)), jump2(n, MergeBigger(m + 1));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = 1;
        jump1[0].merge(0, 1);
        jump2[0].merge(0, 1);
        
        while(q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();

            int dist = grid[i][j], step = dp[i][j] + 1;
            for(int x = jump2[j].find(i); x <= i + dist and x < m; x = jump2[j].find(x)) {
                dp[x][j] = step;
                jump2[j].merge(x, x + 1);
                jump1[x].merge(j, j + 1);
                q.push({x, j});
            }

            for(int y = jump1[i].find(j); y <= j + dist and y < n; y = jump1[i].find(y)) {
                dp[i][y] = step;
                jump1[i].merge(y, y + 1);
                jump2[y].merge(i, i + 1);
                q.push({i, y});
            }
        }
        
        return dp[m - 1][n - 1];
    }
};