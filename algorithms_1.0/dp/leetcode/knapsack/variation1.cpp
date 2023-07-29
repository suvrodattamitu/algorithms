//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
#include <bits/stdc++.h>
using namespace std;

#define len(x) ((int)x.size()) 
#define rep0(i,n) for(int i = 0; i < n; i++)
#define memo(a) memset(a, -1, sizeof(a));

class Solution {
public:
    int dp[2001][2001];
    int rec(int idx, vector<vector<int>>& piles, int k) {
        if(idx >= len(piles)) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];

        int mx = 0, sum = 0;
        mx = max(mx, rec(idx+1, piles, k)); //dont take from that pile
        rep0(i, len(piles[idx])) {
            sum += piles[idx][i];
            if (k - (i + 1) >= 0) { //or take some certain prefix from that pile, if we can take that much elements.
                mx = max(mx, sum + rec(idx+1, piles, k - (i + 1)));
            }
        }

        return dp[idx][k] = mx;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memo(dp);
        int ans = rec(0, piles, k);
        return ans;
    }
};