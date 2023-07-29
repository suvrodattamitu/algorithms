//https://atcoder.jp/contests/abc286/tasks/abc286_d
#include<bits/stdc++.h>
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

int dp[55][10005];
bool rec(ll idx, ll amount, vi &a, vi &b) {
    if(idx == len(b)) return (amount == 0);
    if(dp[idx][amount] != -1) return dp[idx][amount];
    
    bool is_possible = false;
    for(int i = 0; i <= b[idx]; i++) {
        if(amount-(a[idx]*i) >= 0)
            is_possible |= rec(idx+1, amount-(a[idx]*i), a, b);
    } 
    return dp[idx][amount] = is_possible;
}

int main() {
    ll n, x;
    cin >> n >> x;
    
    vi a(n), b(n);
    rep0(i, n) {
        cin >> a[i] >> b[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    bool ans = rec(0, x, a, b);
    ans ? put("Yes") : put("No");
}