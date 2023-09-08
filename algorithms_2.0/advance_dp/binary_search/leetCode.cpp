//https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/
#include <bits/stdc++.h>
#define int long long

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
    int dp[100005];
     // next non-conflicting house range index that can be sold
    int search(int idx, int end, vector<vector<int>>& offers){
        int n = len(offers), ans = -1, lo = idx, hi = n-1;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int start = offers[mid][0];
            if(start > end) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    int rec(int idx, vector<vector<int>>& offers) {
        if(idx == len(offers) || idx == -1) return 0;

        if(dp[idx] != -1) return dp[idx];

        //not sell
        int not_sell = rec(idx+1, offers);

        //sell
        int next_possible_idx = search(idx+1, offers[idx][1], offers);
        int sell = offers[idx][2] + rec(next_possible_idx, offers);

        return dp[idx] = max(sell, not_sell);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(all(offers));

        memo(dp);

        int ans = rec(0, offers);
        return ans;
    }
};