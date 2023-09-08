//https://leetcode.com/problems/count-stepping-numbers-in-range/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define For(i, left, right, cnt) for(ll i = left; i < right; i++)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define get(n) (cin >> n);
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
    ll dp[101][2][2][11];
    ll rec(string& number, ll idx, ll prev, bool is_zero, bool tight) {
        if(idx == len(number)) return is_zero != 1;
        
        if (dp[idx][tight][is_zero][prev] != -1) return dp[idx][tight][is_zero][prev];

        ll ans = 0, up = tight ? (number[idx] - '0') : 9;
        for(int dig = 0; dig <= up; dig++) {
            bool will_zero = (is_zero && dig == 0);
            if(is_zero) {
                ans += rec(number, idx+1, dig, will_zero, (tight & (dig == up)));
            } else  {
                if(abs(dig-prev) == 1) {
                    ans += rec(number, idx+1, dig, will_zero, (tight & (dig == up)));
                }
            }
        }

        ans %= MOD;
        return dp[idx][tight][is_zero][prev] = ans;
    }

    int countSteppingNumbers(string low, string high) {
        memo(dp);
        ll l = rec(low, 0, 0, 1, 1);
        
        memo(dp);
        ll r = rec(high, 0, 0, 1, 1);
        
        ll res = r - l;
        res += MOD;
        res %= MOD;
        
        ll add = true;
        rep1(i, len(low)-1) {
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        }

        if (add) res++;
        res %= MOD;

        return res;
    }
};