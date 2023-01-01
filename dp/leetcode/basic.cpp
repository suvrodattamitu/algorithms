//https://leetcode.com/problems/is-subsequence/description/
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
    int is_subsequence(string& s, string& t, int cur_s, int cur_t) {    
        if(cur_s == 0 || cur_t == 0) return 0;

        if(s[cur_s-1] == t[cur_t-1]) {
            return 1 + is_subsequence(s, t, cur_s-1, cur_t-1);
        }

        return is_subsequence(s, t, cur_s, cur_t-1);
    }

    bool isSubsequence(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        if(is_subsequence(s, t, s_len, t_len) == s_len) {
            return true;
        }

        return false;
    }
};