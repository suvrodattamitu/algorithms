//https://cses.fi/problemset/task/1072
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

typedef vector<ll> vi;

void solve() {
	int n;
	get(n);
	
	rep1(i, n) {
		ll a = i*i;
		ll total = a*(a-1)/2;
		if(i > 2) total -= 4*(i-1)*(i-2);
		put(total);
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    while(tc--) {
		solve();
	}

    return 0;
}