//https://www.codechef.com/submit/SUMPRODSEG?tab=statement
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
    ll x,y;
    cin >> x >> y;
    
    ll l1 = x/2;
    ll r1 = (x+1)/2;
    for(ll l = 1; l <= sqrt(y); l++)
    {
        if((y%l) != 0)
            continue;
            
        ll r = y/l;
        if(r < l)
            break;
            
        if(l > r1 || r < l1) {
            cout << l1 << ' ' << r1 << '\n';
            cout << l << ' ' << r << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
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