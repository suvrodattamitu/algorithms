//https://www.youtube.com/watch?v=q6J5QuA0LaU
//https://www.codechef.com/problems-old/ABCXOR

#include <iostream>
using namespace std;

#define ll long long
#define ld long double 
#define MOD 1000000007

void solve() {
    ll n, k;
    cin >> n >> k;
    ll p = pow(2,n);
    ll ans = (p-1) * (p-2);
    cout << ans << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1;

	cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}