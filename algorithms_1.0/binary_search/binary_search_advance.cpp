//https://codeforces.com/contest/1749/problem/C
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
const int MOD = 1000000007;

typedef vector<ll> vi;

bool check(vector<int> a, int n, int k)
{
    for(int i = 0; i < k; i++)
    {
        if(a[i+k-1] > i+1) return false;
    }
 
    return true;
}

void solve() {
    ll n;
    get(n);
    
    vector<int> arr(n);
    rep0(i, n) {
        get(arr[i]);
    }
    
    sort(all(arr));
    
    int low = 0, high = n, ans = 0;
	while(low <= high) {
		ll mid = (low+high) / 2;

		if(check(arr, n, mid)) {
		    low = mid + 1;
			ans = mid;
		} else {
		    high = mid - 1;
		}
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