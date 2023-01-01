//https://codeforces.com/contest/1312/problem/C
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
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll MX = (1LL<<60);
const int LOG = 60;
const long long oo = 1e16;
const ll N = 1e5+10;
typedef vector<ll> vi;
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
    ll n, k;
    cin >> n >> k;

    vector<int> freq(LOG, 0);
    vector<ll> arr(n);
    rep0(i, n) {
        get(arr[i]);
    }
    
    for(ll a : arr) {
        int position = 0;
 
        while (a > 0) {
            freq[position] += a % k;
            a /= k;
            position++;
        }
    }
 
    for (int p = 0; p < LOG; p++) {
        if (freq[p] > 1) {
            put("NO");
            return;
        }
    }
    
    put("YES");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}