//https://www.codechef.com/JULY222D/problems/SUMOFPROD1
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <string>

using namespace std;

#define ll long long
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

    vi a(n);
    rep0(i, n) cin >> a[i];

    ll cnt = 0, ans = 0;
    rep0(i, n) {
        if(a[i] == 1) {
            cnt++;
            ans += cnt;
        } else {
            cnt = 0;
        }
    }

    cout << ans << endl;
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