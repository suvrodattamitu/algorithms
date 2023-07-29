//https://www.youtube.com/watch?v=W1k8fXFIHTY
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
 
ll dp[5005][5005];
ll rec(ll i, ll j, vi& arr) {
    if(i == j) return arr[i];
    if(j - i == 1) return max(arr[j], arr[i]);
    
    if(dp[i][j] != -1) return dp[i][j];
    
    //if me choose first i, 
        //he would choose i+1 or j, he would return a sum that would make my total ans smaller
        //if me chooise a0 and he choose a1 then he choose a1 such a way that my ans would minimum -> a0, a1, (a2, a3, a4)
        //if me choise a0 and he choose a4 -> a0, (a1, a2, a3), a4 
        //(a, b, c, d) inside brackets means (we had these subarray to compute now)

    ll a = arr[i] + min(rec(i+2, j, arr),  rec(i+1, j-1, arr));
    
    //if me choose last j
        //he can choose i or he can chooise j-1
    ll b = arr[j] + min(rec(i+1, j-1, arr), rec(i, j-2, arr));  
    
    return dp[i][j] = max(a, b);
}
 
 
void solve() {
    ll n;
    get(n);
    
    memo(dp);
    
    vi arr(n);
    rep0(i, n) get(arr[i]);
    
    ll ans = rec(0, n-1, arr);
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