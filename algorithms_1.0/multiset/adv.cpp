//https://www.codechef.com/submit/INCADD
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <string>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)

typedef vector<ll> vi;

void solve() {
	ll n, q;
	cin >> n >> q;
	
	vi a(n);
	rep0(i, n) {
	    get(a[i]);
	}
	
	multiset<ll> ms;
	rep0(i, n-1) {
	    ms.insert((a[i+1] - a[i]));
	}
	
	ll idx, x;
	while(q--) {
	    get(idx);
	    get(x);
	    idx--;
	    
	    if(idx-1 >= 0) {
	        ms.erase(ms.lower_bound(a[idx] - a[idx-1]));
	        ms.insert(x - a[idx-1]);
	    }

	    if(idx+1 < n) {
	        ms.erase(ms.lower_bound(a[idx+1] - a[idx]));
	        ms.insert(a[idx+1] - x);
	    }
	    
	    a[idx] = x;
	    
    	ll ans = *ms.begin();
    	if(ans < 0) put(abs(ans));
    	else put(0);
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