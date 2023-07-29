//https://www.codechef.com/START51C/problems/DIFFMED
//https://www.youtube.com/watch?v=eKniIgSE4n4

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define all(a) (a.begin()), (a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mpp;
typedef pair<ll,ll> pll;

void solve() 
{
	ll n;
	cin >> n;

	int l = 0, r = 0;
	
	vi arr(n+1);
	arr[1] = 0;
	for(int i = 2; i <= n; i++) {
	    if(i%2 == 0) arr[i] = --l;
	    else arr[i] = ++r;
	}
	
	for(int i = 1; i <= n; i++) {
	   cout << arr[i] - l + 1 << " ";
	}
	
	cout << endl;
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