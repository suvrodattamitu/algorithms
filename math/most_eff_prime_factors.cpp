//https://www.codechef.com/JUNE221C/problems/DISTGCD
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

#define ll long long

ll factors(ll n) {
    vector<ll> ans;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n%i == 0) {
            if(n/i == i) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    
    return ans.size();
}

void solve() {
    ll a, b;
    cin >> a >> b;
    
    ll val = abs(a-b);

    cout << factors(val) << endl;
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