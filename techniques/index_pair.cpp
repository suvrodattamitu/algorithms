//https://codeforces.com/contest/1703/problem/F
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
	int n;
	cin >> n;

	vi arr(n+1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
	    cin >> arr[i];
	}
    
    vi v;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] >= i) continue;
        ll lb = (ll)(lower_bound(v.begin(), v.end(), arr[i]) - v.begin());
        ans += lb;
        v.push_back(i);
    }
    
    cout << ans << endl;
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