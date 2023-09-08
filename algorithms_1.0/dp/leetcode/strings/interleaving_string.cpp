//https://leetcode.com/problems/interleaving-string/
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
    ll dp[105][105][205];
    bool rec(int idx1, int idx2, int idx3, string& s1, string& s2, string& s3) {
        if(idx3 == len(s3)) {
            return (idx1 == len(s1) && idx2 == len(s2));
        }

        if(dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];

        char ch1 = '$', ch2 = '$';
        if(idx1 < len(s1)) ch1 = s1[idx1];
        if(idx2 < len(s2)) ch2 = s2[idx2];

        bool ans = false;
        if(ch1 == s3[idx3]) {
            ans |= rec(idx1+1, idx2, idx3+1, s1, s2, s3);
        } 

        if(ch2 == s3[idx3]) {
            ans |= rec(idx1, idx2+1, idx3+1, s1, s2, s3);
        }

        return dp[idx1][idx2][idx3] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memo(dp);
        bool ans = rec(0, 0, 0, s1, s2, s3);
        return ans;
    }
};