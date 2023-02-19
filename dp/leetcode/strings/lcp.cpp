//https://leetcode.com/problems/longest-palindromic-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

#define len(a) ((int)a.size())

class Solution {
public:
    int dp[1005][1005];
    int rec(string& s, string& t, int i, int j) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] != t[j]) {
            int a = rec(s, t, i-1, j);
            int b = rec(s, t, i, j-1);
            return dp[i][j] = max(a, b);
        } else {
            return dp[i][j] = 1+rec(s, t, i-1, j-1);
        }
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());

        memset(dp, -1, sizeof(dp));

        int n = len(s)-1;
        int ans = rec(s, t, n, n);
        return ans;
    }
};