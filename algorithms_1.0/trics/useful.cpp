//https://codeforces.com/contest/1714/problem/E
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 1000000007;
const int N = 1e5+10;
typedef vector<ll> vi;

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

bool possible(ll cur, ll mx) {
    if(cur == mx) return true;
    
    vi a;
    int tmp_cur = cur;
    while(tmp_cur - cur <= 20) {
        if(tmp_cur%10 == 0) break;
        tmp_cur += (tmp_cur%10);
        
        if(tmp_cur == mx) return true;
        a.pb(tmp_cur);
    }
    
    for(int i : a) {
        if(mx > i && (mx-i)%20 == 0) return true;
    }
    
    return false;
}

void solve() {
    ll n;
    get(n);
    
    vi arr(n);
    rep0(i, n) {
        get(arr[i]);
        
        //if it is odd, make it even
        if(arr[i]%2) arr[i] += (arr[i]%10);
    }
    
    ll mx = *max_element(all(arr));
    
    int ok = 1;
    rep0(i, n) {
        if(!possible(arr[i], mx)) {
            ok = 0;
            break;
        }
    }
    
    if(ok) put("Yes");
    else put("No");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll tc;
	get(tc);

	while(tc--) {
	    solve();
	}

    return 0;
}