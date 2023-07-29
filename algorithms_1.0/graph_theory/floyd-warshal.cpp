//https://atcoder.jp/contests/abc286/tasks/abc286_e
#include <bits/stdc++.h>
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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n;
    get(n);

    vector<ll> a(n);
    get(a);

    vector<vector<pair<ll,ll>>> A(n, vector<pair<ll,ll>>(n, make_pair(oo, oo)));
    
    for(int i = 0; i < n; i++) {
        string s;
        get(s);
        for(int j = 0; j < n; j++) {
            if(s[j] == 'Y') A[i][j] = {1, -a[j]};
        }
        A[i][i] = {0, 0};
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                A[i][j] = min(A[i][j], {A[i][k].first + A[k][j].first, A[i][k].second + A[k][j].second});
            }
        }
    }

    ll q;
    get(q);
    while(q--) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        auto pa = A[u][v];
        if(pa.first >= oo) {
            out("Impossible");
            continue;
        }
        out(pa.first, -pa.second + a[u]);
    }
}