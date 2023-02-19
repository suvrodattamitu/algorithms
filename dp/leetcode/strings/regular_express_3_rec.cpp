//https://leetcode.com/problems/regular-expression-matching/description/
#include <bits/stdc++.h>
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
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int dp[25][35];
    bool check(string &s, string &p, int i, int j, int &m, int &n) {
        if(i == m && j == n) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool valid = (i < m) && (s[i] == p[j] || p[j] == '.');
        if(j+1 < n && p[j+1] == '*') {
            return dp[i][j] = check(s, p, i, j+2, m, n) || valid && check(s, p, i+1, j, m, n);
        }
        if(valid) {
            return dp[i][j] = check(s, p, i+1, j+1, m, n);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        memset(dp, -1, sizeof(dp));
        return check(s, p, 0, 0, m, n);
    }
};