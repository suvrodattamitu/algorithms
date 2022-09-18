//https://www.codechef.com/submit/KPRIME
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef map<ll,ll> mpp;
typedef pair<ll,ll> pll;

bool prime[100007];
int factors[100007];
void sieve(ll n) {
	memset(prime, true, sizeof(prime));
 
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
			factors[p] = 1;
            for (int i = 2; p * i <= n; i++) {
                prime[p*i] = false;
				factors[p*i]++;
			}
        }
    }
}

void solve() 
{
	ll a, b, k;
	cin >> a >> b >> k;

	int cnt = 0;
	for(int i = a; i <= b; i++) {
		if(factors[i] == k) {
			++cnt;
		}
	}

	cout << cnt << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	sieve(100001);

	int tc = 1 ;
	cin >> tc;
    while(tc--) {
		solve();
	}
    return 0;
}