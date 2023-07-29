//https://codeforces.com/problemset/problem/975/C
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

#define ll long long
#define ld long double 
#define MOD 1000000007

void standing_warriors(vector<ll> &arr, vector<ll> &krr) {
    vector<ll> ps(arr.size());
    partial_sum(arr.begin(), arr.end(), ps.begin());
    
    ll current_k = 0;
    for(ll k : krr) {
        current_k += k;
        
        if(current_k >= ps.back()) current_k = 0;
        
        auto low = lower_bound(ps.begin(), ps.end(), current_k);
        ll dis = low - ps.begin();
        
        ll ans = arr.size() - dis;
        
        if(*low == current_k) ans -= 1;
        
        cout << ans << endl; 

        //cout << distance (low, ps.end ()) - (*low == current_k) << endl;
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> krr(q);
    for(int i = 0; i < q; i++) {
        cin >> krr[i];
    }
    
    standing_warriors(arr, krr);
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1;

	//cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}