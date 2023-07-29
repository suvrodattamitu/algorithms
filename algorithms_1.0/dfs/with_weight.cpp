//https://leetcode.com/contest/weekly-contest-322/problems/minimum-score-of-a-path-between-two-cities/
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
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll N = 1e6+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

vector<pii> g[111111];
bool vis[111111];

ll res;
void dfs(int u){
    if(vis[u]) return;
    
    vis[u] = 1;
    for(auto v : g[u]){
        dfs(v.first);
        res = min(res, v.second);
    }
}

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        rep1(i, n) g[i].clear(), vis[i] = 0;
        
        for(auto row : roads) {
            g[row[0]].pb({row[1], row[2]});
            g[row[1]].pb({row[0], row[2]});
        }
        
        res = 1000000000;
        dfs(1);
        return (int) res;        
    }
};