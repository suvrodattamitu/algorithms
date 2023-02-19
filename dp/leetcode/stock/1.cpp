//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
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

class Solution {
public:
    int dp[100005][5];
    int rec(int i, int buy, vector<int>& prices, int trans = 1) {
        if(trans <= 0 || i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy) {
            // buy it
            int a = -prices[i] + rec(i+1, !buy, prices, trans);
            // not buy it
            int b = rec(i+1, buy, prices, trans);
            return dp[i][buy] = max(a, b);
        }  else {
            // sell it
            int a = prices[i] + rec(i+1, !buy, prices, trans-1);
            // not sell it
            int b = rec(i+1, buy, prices, trans);
            return dp[i][buy] = max(a, b);
        }
    }

    int maxProfit(vector<int>& prices) {
        // rec(i, buy/sell, prices, trans = 1)
        memo(dp);
        int ans = rec(0, 1, prices);
        return ans;
    }
};