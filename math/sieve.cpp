//https://www.codechef.com/submit/CHEFMGX
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

ll n = 10000007;
bool prime[10000007];
ll cnter[10000007];

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
	ll cnt = 0;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
			cnter[p] = ++cnt;
        } else {
			cnter[p] = cnter[p-1];
		}
    }
}

void solve() 
{
	ll x, y;
	cin >> x >> y;
	
	cout << (y-x) - (cnter[y] - cnter[x+1]) << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
	cin >> tc;

	SieveOfEratosthenes();

    while(tc--) {
		solve();
	}

    return 0;
}