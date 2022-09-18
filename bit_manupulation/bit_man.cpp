//https://codeforces.com/contest/1546/problem/B
#include<iostream>
#include<vector>
using namespace std;

#define ll long long  

void solve() 
{
	ll n, m;
    cin >> n >> m;

    n = (2*n) - 1;
    
	ll ans[n+1];
	memset(ans, 0, sizeof(ans));
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
			ans[j] ^= str[j];
        }
    }

	for(int j = 0; j < m; j++) {
		putchar(ans[j]);
	}

	cout << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) 
	{
        solve();
    }

    return 0;
}