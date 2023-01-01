//https://atcoder.jp/contests/abc282/tasks/abc282_d
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

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

bool bfs(int src, vector<vector<int>>& graph, vector<int>& color, vector<int>& vec, ll cnt[2]) {
    queue<int> q;

    q.push(src);
    color[src] = 0;

    while(!q.empty()) {
        src = q.front();
        q.pop();

        vec.push_back(src);
        cnt[color[src]]++;

        for(auto v : graph[src]) {
            if(color[v] == -1) {
                q.push(v);
                color[v] = color[src]^1;
            }

            //if src and cur node both has same color
            else if(color[v] == color[src]) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> color(n+1, -1);

    int x, y;
    rep0(i, m) {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    ll ans = 0;
    ll cnt[2] = {0};
    bool biparted = 1;
    rep1(i, n) {
        if(color[i] == -1) {
            vector<int> vec;
            cnt[1] = cnt[0] = 0;
            biparted &= bfs(i, graph, color, vec, cnt);
            
            if(!biparted) {
                put(0);
                return;
            }

            for(auto u : vec) {
                ans += n - cnt[color[u]] - len(graph[u]);
            }
        }
    }
    put(ans/2);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	//get(tc);
	while (tc--) {
		solve();
	}
}

//a b c d 
//ab 
//ac
//ad
//bc
//bd
//cd