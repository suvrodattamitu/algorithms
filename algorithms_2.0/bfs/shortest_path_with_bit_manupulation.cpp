//https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define spaced(n) (cout << n << " ")
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

class Solution {
public:
    int rows, cols, keys, end, vis[35][35][64];
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {-1, 0, 1, 0};
    map<char, int> bucket;

    bool is_key(char ch) {
        return (ch >= 'a' && ch <= 'z');
    }

    bool is_lock(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

    bool is_valid(int i, int j, vector<string>& grid) {
        if(i >= 0 && i < rows && j >= 0 && j < cols) 
            return (grid[i][j] != '#');
        return false;
    }

    int shortestPathAllKeys(vector<string>& g) {
        rows = len(g);
        cols = len(g[0]);

        queue<pair<pair<int,int>,int>>q;
        rep0(i, rows) {
            rep0(j, cols) {
                char cur = g[i][j];
                if(cur == '@') q.push({{i,j},0});
                if(is_key(cur)) keys++;
            }
        }

        memo(vis);

        int end = (1<<keys)-1;
        int steps = 0;
        while(!q.empty()) {
            int k = len(q);
            while(k--) {
                auto tp = q.front();
                q.pop();
                int x = tp.first.first;
                int y = tp.first.second;
                int mask = tp.second;

                if(mask == end) return steps;

                rep0(h, 4) {
                    int nx = x + dirX[h];
                    int ny = y + dirY[h];
                    if(is_valid(nx, ny, g)) {
                        char cur = g[nx][ny];
                        if(is_key(cur)){
                            int n_mask = mask | (1 << (cur - 'a'));
                            if(vis[nx][ny][n_mask] == -1) {
                                vis[nx][ny][n_mask] = 1;
                                q.push({{nx,ny},n_mask});
                            }
                        }

                        else if(is_lock(cur)) {
                            if((mask & (1 << (cur - 'A'))) == 0) continue;
                            int n_mask = mask;
                            if(vis[nx][ny][n_mask] == -1) {
                                vis[nx][ny][n_mask] = 1;
                                q.push({{nx,ny},n_mask});
                            }
                        }

                        else {
                            int n_mask = mask;
                            if(vis[nx][ny][n_mask] == -1) {
                                vis[nx][ny][n_mask] = 1;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};