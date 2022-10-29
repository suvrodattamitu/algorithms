//https://codeforces.com/contest/1744/problem/D
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) str.length()
#define lena(arr) arr.size() 
#define pb push_back
const int MOD = 1000000007;

typedef vector<ll> vi;

void solve() {
    ll n;
    get(n);
    
    vi a(n), b(n), c(n);
    int cnt = 0;
    rep0(i, n) {
        get(a[i]);
        
        //leading 0 count,
        //that means that this number is divisible by 2 is = its total leading zeros
        //another word 2s factors in a[i] is equal leading zeros of a[i]
        b[i] = __builtin_ctz(a[i]);
        c[i] = __builtin_ctz(i + 1);
        
        cnt += b[i]; // count total leading zeros of arrays
    }
    
    sort(all(c), greater<int>());
    
    int ans = 0;
    rep0(i, n) {
      if (cnt < n){
        cnt += c[i];
        ans++;
      }
    }
    
    if (cnt < n){
      put(-1);
    } else {
      put(ans);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
		solve();
	}

    return 0;
}