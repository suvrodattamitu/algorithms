//https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/
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
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define spaced(n) (cout << n << " ")
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
     
    ll dp[12][2][2][20][12][12], kk;
    ll rec(string& number, ll idx, ll sum, bool leading_zero, bool tight, int even, int odd) {
        if(idx == len(number)) {
            return !leading_zero && odd == even && sum == 0;
        }
        
        if (dp[idx][tight][leading_zero][sum][even][odd] != -1) return dp[idx][tight][leading_zero][sum][even][odd];

        ll ans = 0, up = tight ? (number[idx] - '0') : 9;
        for(int dig = 0; dig <= up; dig++) {
            if(leading_zero && dig == 0) {
                ans += rec(number, idx+1, ((sum * 10) + dig)%kk, leading_zero & (dig == 0), (tight & (dig == up)), even , odd);
            } else {
                ans += rec(number, idx+1, ((sum * 10) + dig)%kk, leading_zero & (dig == 0), (tight & (dig == up)), even + (!(dig&1)) , odd + (dig&1));
            }
        }

        return dp[idx][tight][leading_zero][sum][even][odd] = ans; 
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        kk = k;
        
        string ls = to_string(low-1), rs = to_string(high);
        
        memo(dp);
        ll l = rec(ls, 0, 0, 1, 1, 0, 0);
        
        memo(dp);
        ll r = rec(rs, 0, 0, 1, 1, 0, 0);
        
        return r - l;
    }
};
