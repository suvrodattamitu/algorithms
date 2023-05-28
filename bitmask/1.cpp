//https://leetcode.com/problems/beautiful-arrangement/description/
#include <bits/stdc++.h>
using namespace std;

/* Using Bitmask */
class Solution {
public:
    int dp[16][1 << 16];
    int rec(int i, int n, int mask) { 
        if(i > n) return 1;

        if(dp[i][mask] != -1) return dp[i][mask];

        int ans = 0;
        for(int j = 1; j <= n;j++) {
            if(mask & (1 << (j-1))) continue;
            if(j%i == 0 || i%j == 0) ans += rec(i+1, n, mask | (1 << (j-1)));
        }

        return dp[i][mask] = ans;
    }

    int countArrangement(int n) {
        memset(dp, -1, sizeof(dp));
        return rec(1, n, 0);
    }
};

/* Using Backtracking */
class Solution {
public:
    int ans = 0;
    int visited[20];

    void rec(int pos, int n) {
        if(pos > n) ++ans;
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && (i%pos == 0 || pos%i == 0)) {
                visited[i] = true;
                rec(pos+1, n);
                visited[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        rec(1, n);
        return ans;
    }
};