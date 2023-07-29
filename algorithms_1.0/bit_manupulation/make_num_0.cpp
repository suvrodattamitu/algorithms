//https://leetcode.com/contest/weekly-contest-333/problems/minimum-operations-to-reduce-an-integer-to-0/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int minOperations(int n) {        
        ll ans = 0;
        rep0(i, 32) {
            if (n & (1 << i)) {
                if (n & (1 << (i + 1))) {
                    n += (1 << i);
                    ans += 1;
                } else {
                    n -= (1 << i);
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};