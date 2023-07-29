//https://cses.fi/problemset/task/1636
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

void out(){cout << '\n';}
template<class T>void out(const T& a){cout << a << '\n';}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){cout << head << ' ';out(tail...);}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...);
#endif

vector<vector<int>> dp;
// ll rec(ll idx, ll cur_sum, vi& arr) {
//     if (cur_sum == 0) return 1;
    
//     if (cur_sum < 0) return 0;
    
//     if (idx < 0) return 0;
    
//     if(dp[idx][cur_sum] != -1) return dp[idx][cur_sum];
    
//     ll taken = rec(idx, cur_sum - arr[idx], arr);
//     ll not_token = rec(idx - 1, cur_sum, arr);

//     return dp[idx][cur_sum] = taken + not_token;
// }

ll iterative(ll totalSum, vi& arr) {
    int n = len(arr);
    dp[0][0] = 1; // you can ignore it
    for (int i = 0; i <= n; i++) {
        for (int cur_sum = 0; cur_sum <= totalSum; cur_sum++) {
            if(i == 0) {
                if(cur_sum == 0) {
                    dp[i][cur_sum] = 1;
                } else {
                    dp[i][cur_sum] = 0;
                }
            }
            else {
                dp[i][cur_sum] = dp[i-1][cur_sum];
                int left = cur_sum - arr[i-1];

                if (left >= 0) {
                    dp[i][cur_sum] += dp[i][left];
                    dp[i][cur_sum] %= MOD;
                }
            }
        }
    }

    return dp[n][totalSum];
}

void solve() {
    ll total_coins, total_sum;
    get2(total_coins, total_sum);
    
    vi arr(total_coins);
    rep0(i, total_coins) {
        get(arr[i]);
    }
    
    // dp.resize(total_coins+1, vector<ll>(total_sum+1, -1));
    // ll ans = rec(total_coins-1, total_sum, arr);
    
    dp.resize(total_coins+1, vector<int>(total_sum+1, 0));

    ll ans = iterative(total_sum, arr);
    ans += MOD;
    ans %= MOD;
    
    put(ans);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	//get(tc);
	while (tc--) {
		solve();
	}
}
