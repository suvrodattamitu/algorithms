//https://leetcode.com/problems/perfect-squares/?envType=study-plan-v2&id=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10005];
    int rec(int n) {
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int mn = INT_MAX;
        for(int i = 1; i*i <= n; i++) {
            int sq = i * i;
            if(n-sq >= 0) {
                //dont do this n -= sq, then rec(n)
                mn = min(mn,  1 + rec(n-sq));
            }
        }

        return dp[n] = mn;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(n);
        return ans;
    }
};