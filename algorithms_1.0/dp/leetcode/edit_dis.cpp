//https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define len(a) ((int)a.size())

class Solution {
public:
    int dp[505][505];
    int rec(int i, int j, string& word1, string& word2) {
        if (i == 0) {
            return j;
        }

        if (j == 0) {
            return i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] != word2[j-1]) {
            int ins = rec(i, j-1, word1, word2);
            int del = rec(i - 1, j, word1, word2);
            int rep = rec(i - 1, j - 1, word1, word2);

            return dp[i][j] = min(ins, min(del, rep)) + 1;
        } else {
           return dp[i][j] = rec(i-1, j-1, word1, word2);
        }
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(len(word1), len(word2), word1, word2);
        return ans;
    }
};