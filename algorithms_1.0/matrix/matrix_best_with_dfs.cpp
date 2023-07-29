//https://atcoder.jp/contests/abc300/tasks/abc300_c
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

void out(){cout << '\n';}
template<class T>void out(const T& a){cout << a << '\n';}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){cout << head << ' ';out(tail...);}

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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...);
#endif

int size = 0;

bool valid(int i, int j, int rows, int cols, vector<vector<char>> matrix) {
    if(i >= 0 && j >= 0 && i < rows && j < cols && matrix[i][j] == '#') return 1;
    return 0;
}

int dfs1(int i, int j, int rows, int cols, vector<vector<char>> matrix) {
    if(valid(i, j, rows, cols, matrix)) {
        return 1 + dfs1(i+1, j+1, rows, cols, matrix);
    }
    
    return 0;
}

int dfs2(int i, int j, int rows, int cols, vector<vector<char>> matrix) {
    if(valid(i, j, rows, cols, matrix)) {
        return 1 + dfs2(i+1, j-1, rows, cols, matrix);
    }
    
    return 0;
}

int dfs3(int i, int j, int rows, int cols, vector<vector<char>> matrix) {
    if(valid(i, j, rows, cols, matrix)) {
        return 1 + dfs3(i-1, j+1, rows, cols, matrix);
    }
    
    return 0;
}

int dfs4(int i, int j, int rows, int cols, vector<vector<char>> matrix) {
    if(valid(i, j, rows, cols, matrix)) {
        return 1 + dfs4(i-1, j-1, rows, cols, matrix);
    }
    
    return 0;
}

int get_size(int i, int j, vector<vector<char>> matrix, int rows, int cols) {
    if(matrix[i][j] == '#') {
        int a = dfs1(i+1, j+1, rows, cols, matrix);
        int b = dfs2(i+1, j-1, rows, cols, matrix); 
        int c = dfs3(i-1, j+1, rows, cols, matrix);
        int d = dfs4(i-1, j-1, rows, cols, matrix);
        int mn = min(min(a, b), min(c, d));
        return mn;
    }
    
    return 0;
}

void solve() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<char>> matrix(rows, vector<char>(cols));
    rep0(i, rows) {
        rep0(j, cols) {
            get(matrix[i][j]);
        }
    }
    
    map<int, int> mp;
    rep0(i, rows) {
        rep0(j, cols) {
            int star_size = get_size(i, j, matrix, rows, cols);
            mp[star_size]++;
        }
    }
    
    int mn = min(rows, cols);
    rep1(i, mn) {
        cout << mp[i] << " ";
    }
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

/*
in single dfs

H, W = map(int, input().split())
C = [list(input()) for _ in range(H)]
def dfs(y, x):
    cnt = 1
    C[y][x] = '.'
    for dy in range(-1, 2):
        for dx in range(-1, 2):
            y2, x2 = y + dy, x + dx
            if 0 <= y2 < H and 0 <= x2 < W and C[y2][x2] == '#':
                cnt += dfs(y2, x2)
    return cnt
ans = [0 for _ in range(min(H, W))]
for y in range(H):
    for x in range(W):
        if C[y][x] == '#':
            ans[dfs(y, x) // 4 - 1] += 1
print(' '.join(map(str, ans)))

*/