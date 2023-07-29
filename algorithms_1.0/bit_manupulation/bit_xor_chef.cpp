//https://www.codechef.com/problems/EQBYXOR
#include <iostream>
using namespace std;

#define ll long long

int solve() 
{
    ll a, b, n;
    cin >> a >> b >> n;

    if(a == b) {
        cout << 0 << endl;
        return 0;
    }

    int x = a^b;
    if(x < n) {
        cout << 1 << endl;
        return 0;
    }

    int last = 0;
    for(int j=0; j <= 30; ++j) {
        if(x>>j&1) {
            last = 1<<j;
        }
    }

    if(last < n) {
        cout << 2 << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}