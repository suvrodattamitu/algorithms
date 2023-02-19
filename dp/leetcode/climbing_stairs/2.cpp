//https://leetcode.com/problems/min-cost-climbing-stairs/description/
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

class Solution {
public:
    int dp[1005];
    int rec(int i, vector<int>& cost) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(rec(i+1, cost), rec(i+2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int ans = min(rec(0, cost), rec(1, cost));
        return ans;
    }
};