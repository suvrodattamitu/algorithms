//https://cses.fi/problemset/task/1623
//al subsets of an array 
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
    ll n;
	get(n);

	vi arr(n);

    ll totalSum = 0;
	rep0(i, n) {
		get(arr[i]);
		totalSum += arr[i];
	}
	
	ll ans = INT_MAX;
	rep0(i, (1<<n)) {
	    ll subsetSum = 0;
	    rep0(j, n) {
	        if(i&(1<<j)) subsetSum += arr[j];
	    }
	    
	    ans = min(ans, abs(totalSum-2*subsetSum));
	}
	
	put(ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	//cin >> tc;

    while(tc--) {
		solve();
	}

    return 0;
}