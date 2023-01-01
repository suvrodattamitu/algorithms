//https://leetcode.com/contest/weekly-contest-326/problems/closest-prime-numbers-in-range/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e4+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:    
    vi SieveOfEratosthenes(int left, int right)
    {
        bool prime[right+1];
        memset(prime, true, sizeof(prime));
        
        prime[1] = 0;
        for (int p = 2; p * p <= right; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= right; i += p)
                    prime[i] = 0;
            }
        }

        vi primes;
        for (int p = left; p <= right; p++) {
            if (prime[p]) {
                primes.pb(p);
            }
        }
        
        return primes;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vi primes = SieveOfEratosthenes(left, right);
        int n = len(primes);
        
        vector<int> ans(2, 0);
        rep0(i, n-1) {
            ll x = primes[i]; 
            ll y = primes[i+1];
            
            if(ans[0] == 0) {
                ans[0] = x;
                ans[1] = y;
            } else {
               if (y-x < ans[1] - ans[0]) {
                   ans[0] = x;
                   ans[1] = y;
               }
            }
        }
        
        if(ans[0] == 0) {
            return {-1, -1};
        }
        
        return ans;
    }
};