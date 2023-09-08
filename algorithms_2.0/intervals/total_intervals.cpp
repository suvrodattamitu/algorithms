//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a))
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
const ll maxn = 2e5;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

class Solution {
public:
    ll dp[10008];
    ll rec(int idx, vector<array<int, 2>>& arr, int& n) {
        if(arr[idx][1] == n) return 1;
        if(idx == len(arr)) return INT_MAX;
        if(dp[idx] != -1) return dp[idx];

        ll ans = INT_MAX;
        for(int i = idx+1; i < len(arr); i++) {
            if(arr[i][0] > arr[idx][1]) break;
            ans = min(ans, 1 + rec(i, arr, n));
        }

        return dp[idx] = ans;
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<array<int, 2>> arr;
        for(int i = 0; i < len(ranges); i++) {
            int x = max(0, i - ranges[i]);
            int y = min(n, i + ranges[i]);
            
            arr.pb({x, y});
        }

        sort(all(arr));

        memo(dp);

        ll ans = INT_MAX;
        for(int i = 0; i < len(ranges); i++) {
            if(arr[i][0] == 0) {
                ans = min(ans, rec(i, arr, n));
            }
        }

        if(ans == INT_MAX) {
            ans = -1;
        }

        return ans;
    }
};