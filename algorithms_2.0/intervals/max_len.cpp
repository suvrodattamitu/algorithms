// https://leetcode.com/problems/maximum-length-of-pair-chain/description/
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
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    ll dp[1005][2005];
    int rec(int idx, int prev, vector<vector<int>>& pairs) {
        if(idx == len(pairs)) return 0;

        if(dp[idx][prev+1002] != -1) return dp[idx][prev+1002];

        //dont take cur idx
        int take = rec(idx+1, prev, pairs);

        //take cur idx
        int curA = pairs[idx][0], curB = pairs[idx][1];
        int not_take = rec(idx+1, curB, pairs) + (curA > prev);

        return dp[idx][prev+1002] = max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memo(dp);

        sort(all(pairs));
        ll ans = rec(0, -1002, pairs);
        return ans;
    }
};