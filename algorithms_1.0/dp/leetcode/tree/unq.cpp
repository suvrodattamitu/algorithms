//https://leetcode.com/problems/unique-binary-search-trees/
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
    int dp[25];
    int rec(int n) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += rec(i-1) * rec(n-i);
        return dp[n] = ans;
    }

    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(n);
        return ans;
    }
};