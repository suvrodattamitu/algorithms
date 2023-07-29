//https://codeforces.com/contest/1743/problem/C
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

    string str;
    get(str);

    vi arr(n);
    rep0(i, n) get(arr[i]);

    ll ans = 0, mx = -1;
    for(int i = 0; i < n; i++) {
        if(i-1 >= 0 && str[i-1] == '0') {
            mx = arr[i-1];
        }
        if(str[i] == '1') {
            ll mn = arr[i];
            ans += arr[i];
            while(i+1 < n && str[i+1] == '1') {
                ++i;
                mn = min(mn, arr[i]);
                ans += arr[i];
            }

            if(mx != -1) {
                ans += mx;
                ans -= mn;
            }
        }

        mx = -1;
    }

    put(ans);
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