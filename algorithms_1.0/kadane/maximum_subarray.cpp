//https://www.codechef.com/submit/MAXSUBARR
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define S first
#define F second
#define pb push_back
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)

typedef vector<ll> vi;

void solve() {
	ll n, m;
	get(n);

	vi a(n);
	rep0(i, n) get(a[i]);

	get(m);
	vi b(m);
	rep0(i, m) get(b[i]);

    ll mxSum = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < a.size(); i++) {
        max_ending_here = max_ending_here + a[i];
        if (mxSum < max_ending_here)
            mxSum = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }

	rep0(i, m) {
		if(b[i] > 0) mxSum += b[i];
	}

	put(mxSum);
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