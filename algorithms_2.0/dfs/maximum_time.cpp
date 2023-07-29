//https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
#include <bits/stdc++.h>
#include <string.h>
#include <vector.h>
#include <map.h>
#ifdef __LOCAL__
  #include <debug_local.h>
#endif
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
#define get(n) (cin >> n);
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

/*
if one subtrees needs time 6 minutes
another subtrees needs time 5 minutes
another subtrees needs time 4 minutes
then in maximum 6 minutes time it is possible to cover subtrees that needs 5,4 minutes time to spread news
*/

class Solution {
public:
    vector<vector<int>> graph;

    int dfs(int u, vector<int>& informTime) {
        int ans = 0;
        for(int child : graph[u]) {            
            ans = max(ans, informTime[u] + dfs(child, informTime));
        }

        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int>& managers, vector<int>& informTime) {
        graph.resize(n+1);

        int src;
        rep0(i, n) {
            int manager = managers[i];
            if(manager != -1) {
              graph[manager].pb(i);
            } else {
                src = i;
            }
        }

        int ans = dfs(src, informTime);

        return ans;
    }
};


class Solution {
public:
    const int MOD = 1e9 + 7;

int digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


    int count(string num1, string num2, int min_sum, int max_sum) {
        int cnt = 0;
    int n1 = stoi(num1);
    int n2 = stoi(num2);
    for (int i = n1; i <= n2; i++) {
        int sum = digit_sum(i);
        if (sum >= min_sum && sum <= max_sum) {
            cnt++;
        }
    }
    return cnt % MOD;
    }
};