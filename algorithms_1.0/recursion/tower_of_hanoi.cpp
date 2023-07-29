//https://cses.fi/problemset/task/2165
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

bool col[16], diagonal1[16], diagonal2[16], reserved[8][8];
ll ways;

void towerOfHanoi(int n, int a, int b, int c) {
	if(n <= 0) return;
	towerOfHanoi(n-1, a, c, b);
	cout << a << " " << c << endl;
	towerOfHanoi(n-1, b, a, c);
}

void solve() {
	int n;
	get(n);
	
	cout<< (1<<n) - 1 << endl;
	
	towerOfHanoi(n, 1, 2, 3);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    while(tc--) {
		solve();
	}

    return 0;
}