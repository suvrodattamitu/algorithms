//https://www.codechef.com/START42B/problems/MAXIMISEBITS
//https://www.youtube.com/watch?v=G_347ILCarM&t=3s
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

#define ll long long  
#define ull unsigned long long int 

ll Ceil(ll a, ll b){
    ll ans = a/b;
    if(a%b != 0) ans++;
    return ans;
}

void solve() {
	ull n, k;
	cin >> n >> k;

	map<ull,ll> setb;
	for(int i = 0; i < 40; i++) {
		ull x = pow(2.0,i)-1;
		setb[x] = __builtin_popcount(x);
	}

	if(n >= k) {
		cout << k << endl;
		return;
	}
	
	ull pre=0, suc=0;
    for(int i = 1; i < 40; i++) {
		ll x = pow(2.0,i) - 1;
		pre = suc;
		suc = x;
		if(n*x >= k){
			break;
		}
	}

	/*
		sX + pY = k
		X + Y = n [Y = n-X]
		so, X = (k-np)/(s-p)
	*/
	ll X = Ceil((k-n*pre), (suc-pre));
	ll Y = n - X;

	//if sX + pY > k
	ll extra = (suc*X) + (pre*Y) - k;

	cout<<(setb[suc]*X) + (setb[pre]*Y) - (__builtin_popcount(extra)) << endl;
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