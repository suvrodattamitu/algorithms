//https://leetcode.com/problems/word-break/description/
#include <bits/stdc++.h>
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
    int dp[305];
    set<string> word_set;
    bool rec(int start, string &str) {
        if(start == len(str)) return true;

        if(dp[start] != -1) return dp[start];

        for(int end = start+1; end <= len(str); end++) {
            if(word_set.find(str.substr(start, end-start)) != word_set.end() && rec(end, str)) {
                return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
       memo(dp);
       set<string> wtf(wordDict.begin(), wordDict.end());
       word_set = wtf;
       return rec(0, s); 
    }
};

//https://leetcode.com/problems/extra-characters-in-a-string/solutions/3568569/similar-to-word-break-dp/