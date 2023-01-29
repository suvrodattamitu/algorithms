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
const ll MOD = 100000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef vector<vector<ll> > vii;

typedef pair<ll, ll> pii;

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


void solve() {
    ull n;
    get(n);
    
    for(ll p = 2; p*p*p <= n; p++) {
        if(n%p == 0) {
            if(n % (p*p) == 0) {
              cout << p << " " << n/(p*p) << endl;
            } else {
              ll v = sqrt(n/p);
              cout << v << " " << p << "\n";
              //cout << sqrt(n / p) << " " << p << "\n"; this gives wrong
            }
            return;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	get(tc);
	while (tc--) {
		solve();
	}
}