#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
//https://atcoder.jp/contests/abc275/tasks/abc275_b
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 998244353;
const int N = 1e5+10;
typedef vector<ll> vi;

void solve() {
    ull a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    a %= MOD; 
    b %= MOD; 
    c %= MOD;
    d %= MOD;
    e %= MOD;
    f %= MOD;
    
    ull x = ((a*b)%MOD*c)%MOD;
    ull y = ((d*e)%MOD*f)%MOD;
    
    ull z = (x+MOD-y)%MOD;
    put(z);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}