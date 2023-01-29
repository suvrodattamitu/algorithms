//https://atcoder.jp/contests/abc151/tasks/abc151_d
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

int X[4] = {0, 1, 0, -1};
int Y[4] = {-1, 0, 1, 0};
    
void solve() {
    ll rows, cols;
    cin >> rows >> cols;
    
    char grid[rows+1][cols+1];
    ll dist[rows+1][cols+1];
    
    rep0(i, rows) {
        rep0(j, cols) {
            get(grid[i][j]);
        }
    }
    
    ll ans = 0;
    rep0(i, rows) {
        rep0(j, cols) {
            if(grid[i][j] != '#') {
                fill(dist[0], dist[rows+1], oo);
                
                queue<pair<ll, ll>> q;
                q.emplace(i, j);
                dist[i][j] = 0;
                
                ll cur = 0;
                while(q.size()) {
                    ll x, y; 
                    tie(x, y) = q.front(); 
                    q.pop();
                    cur = dist[x][y];
                    
                    for(ll k = 0; k < 4; k++) {
                        ll xx = x + X[k];
                        ll yy = y + Y[k];
                        
                        if(grid[xx][yy] == '#') continue; //valitate 1
                        if(xx < 0 || yy < 0 || xx >= rows || yy >= cols) continue; // validate 2
                        if(dist[xx][yy] > dist[x][y] + 1) {
                            dist[xx][yy] = dist[x][y] + 1;
                            q.emplace(xx, yy);
                        }
                    }
                }
                
                ans = max(ans, cur);
            }
        }
    }
    
    put(ans);
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