//https://leetcode.com/problems/restore-the-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    vector<int> dp;
    int rec(int idx, string& s, int& k) {
        if (idx == s.size()) return 1;

        if (dp[idx] != -1) return dp[idx];

        long long currNum = 0, ways = 0;
        for (int i = idx; i < s.size(); i++)
        {
            int currDig = s[i] - '0';
            currNum = (currNum * 10) + currDig;

            if (currNum < 1 || currNum > k) break;
            int nextWays = rec(i+1, s, k);
            ways += nextWays;
            ways %= MOD;
        }

        return dp[idx] = ways;
    }

    int numberOfArrays(string s, int k) {
        dp.resize(s.size(), -1);
        int ans = rec(0, s, k);
        return ans;
    }
};