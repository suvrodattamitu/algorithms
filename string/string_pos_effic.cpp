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
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mpp;
typedef pair<ll,ll> pll;

void solve() 
{
	ll t;
    cin>>t;
    while(t--)
    {
        ll n, c, q;
        string s;
        cin >> n >> c >> q >> s;
        vector<pair<ll, pll>> a;

        a.pb({0, {0, n-1}});
        ll cur = n;
        rep0(i,c)
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            a.pb({cur, {l,r}});
            cur += r-l+1;
        }
        while(q--)
        {
            ll k;
            cin >> k;
            k--;
            for(int i = c; i >= 1; i--)
            {
                if(k >= a[i].F)
                {
                    k = k - a[i].F + a[i].S.F;
                }
            }
            cout << s[k] << "\n";
        }
    }
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