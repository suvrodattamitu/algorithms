//https://leetcode.com/problems/count-of-integers/
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
    int dp[30][401][3];
    bool is_ok(string& left, int min_sum, int max_sum) {
        int sum = 0;
        rep0(i, len(left)) {
            sum += (left[i] - '0');
        }

        return (sum >= min_sum && sum <= max_sum);
    }

    int rec(string& right, int n, int digit_sum, int min_sum, int max_sum, int tight) {
        if(digit_sum >  max_sum) return 0;
        
        if(n == 0) {
            return (digit_sum >= min_sum && digit_sum <= max_sum);
        }

        if(dp[n][digit_sum][tight] != -1) return dp[n][digit_sum][tight];

        int ans = 0, ub = tight ? (right[len(right) - n] - '0') : 9;
        for(int dig = 0; dig <= ub; dig++) {
            ans += rec(right, n-1, digit_sum + dig, min_sum, max_sum, (tight && (dig == ub)));
            ans %= MOD;
        }

        return dp[n][digit_sum][tight] = ans;
    }

    int count(string left, string right, int min_sum, int max_sum) {
        memo(dp);
        int ans = rec(right, len(right), 0, min_sum, max_sum, 1);

        memo(dp);
        ans -= rec(left, len(left), 0, min_sum, max_sum, 1);

        if(is_ok(left, min_sum, max_sum)) ++ans;

        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        
        return ans;
    }
};