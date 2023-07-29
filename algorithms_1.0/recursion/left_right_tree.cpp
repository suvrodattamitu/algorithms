//https://codeforces.com/contest/1741/problem/D
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) str.length()
#define lena(arr) arr.size() 
#define pb push_back

typedef vector<ll> vi;

const int MAXM = 300300;

int n, m;
int arr[MAXM];

ll rec(int l, int r) {
    if (r - l == 1) return 0;
    int mid = (l+r) / 2;
    ll mxL = *max_element(arr+l, arr+mid);
    ll mxR = *max_element(arr+mid, arr+r);
    
    int ans = 0;
    if(mxL > mxR) {
        ++ans;
        for (int i = 0; i < (mid - l); ++i)
			swap(arr[l + i], arr[mid + i]);
    }
    
    return rec(l, mid) + rec(mid, r) + ans;
}

void solve() {
	ll n;
	get(n);
	
	rep0(i, n) get(arr[i]);
	
	ll ans = rec(0, n);
	if(!is_sorted(arr, arr+n)) {
	    ans = -1;
	}
	
	put(ans);
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