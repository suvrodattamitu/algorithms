//https://www.codechef.com/submit/PYTHAGORAS
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

int is_square[500005];
void solve() {
	ll n;
	get(n);

	int a, b, ok = 0;
	for(int i = 0; i*i <= n; i++)
	{
		if(is_square[n-i*i] != -1)
		{
			a = i;
			b = is_square[n-(i*i)];
			cout << a << " " << b << endl;
			return;
		}
	}

	put(-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    memset(is_square,-1,sizeof(is_square));
    for(int i = 0; i*i < 500005; i++)
	{
		is_square[i*i] = i ;
	}

	int tc = 1 ;
    while(tc--) {
		solve();
	}

    return 0;
}