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

ll n, dp[501][100000], requiredSum;
ll rec(int idx, int sum) {
	if(sum == requiredSum) return 1;
	if(idx == n) return 0;
	
	if(dp[idx][sum] >= 0) return dp[idx][sum];
	
	ll not_take = rec(idx+1, sum);
	not_take %= MOD;
	
	ll take = rec(idx+1, sum+idx+1);
	take %= MOD;
	
	dp[idx][sum] = (take + not_take) % MOD;
	return dp[idx][sum];
}

int main()
{	
	get(n);
	memo(dp);
	
	ll total = (n*(n+1))/2;
	
	if(total%2!=0) {
	    put(0);
    } else {
	    requiredSum = total/2;
	    ll ans = rec(1, 1);
        put(ans);
	}
}