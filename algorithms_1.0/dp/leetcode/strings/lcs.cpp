//https://leetcode.com/problems/longest-common-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

#define len(x) ((int)x.size()) 

// for string start dp from end to start
class Solution {
public:
    int dp[1005][1005];
    int rec(int i, int j, string& text1, string& text2) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans++;
            ans += rec(i-1, j-1, text1, text2);
        } else {
            ans += max(rec(i-1, j, text1, text2), rec(i, j-1, text1, text2));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(len(text1)-1, len(text2)-1, text1, text2);
        return ans;
    }
};