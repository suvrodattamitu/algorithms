//https://atcoder.jp/contests/abc301/tasks/abc301_d
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
#define get(n) (cin >> n)
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

void solve() {
    string str;
    get(str);
    
    ll n;
    get(n);
    
    ll sum = 0;
    int sz = len(str);
    for(int i = 0; i < sz; i++) {
        if(str[i] == '1') {
            sum += 1LL<<(sz-1-i);
        }
    }
    
    if(n < sum) {
        put(-1);
        return;
    }
    
    for (int i = 0; i < sz; i++) {
        if (str[i] == '?' && sum + (1LL << (sz - 1 - i)) <= n) {
            sum += (1LL << (sz - 1 - i));
        }
    }
    
    put(sum);
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


..................
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

string s;
int n,curr;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> s;
    cin >> n;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            curr += (1LL<<i);
        }
    }
    if(curr>n){
        cout << -1 << "\n";
        return 0;
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='?'){
            if(curr+(1LL<<i)<=n){
                curr += (1LL<<i);
            }
        }
    }
    cout << curr << "\n";
}
