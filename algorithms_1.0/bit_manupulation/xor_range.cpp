//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/yasser-and-xor-c7c23323/
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define F first
#define S second
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mpp;
typedef pair<ll,ll> pll;

void solve() 
{  
    int n, q;
	cin >> n >> q;
	vector<ll>v(n + 2), L(n + 2, 0), R(n + 2, 0);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		L[i] = L[i - 1] ^ v[i];
	}
	for (int i = n; i >= 1; i--)
	{
		R[i] = R[i + 1] ^ v[i];
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		cout << (L[l - 1] ^ R[r + 1]) << endl;
	}
}

int main() 
{
    ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    
	int tc = 1 ;
    
	//cin >> tc;

    while(tc--) 
	{
		solve();
	}

    return 0;
}