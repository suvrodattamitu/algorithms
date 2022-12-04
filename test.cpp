//https://leetcode.com/problems/word-search/description/
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

int dRow[4] = { 0, 1, 0, -1 };
int dCol[4] = { -1, 0, 1, 0 };

int row, col;

bool isValid(int i, int j)
{
    // If cell is out of bounds
    if (i < 0 || j < 0 || i >= row || j >= col) return false;
    
    // Otherwise, it can be visited
    return true;
}

bool dfs(int i, int j, int cnt, vector<vector<char>>& grid, string& word) {
    if(cnt == word.length()) return true;
    if(!isValid(i, j)) return false;

    if (word[cnt] == grid[i][j]) {
        grid[i][j] = ' ';
        for (int x = 0; x < 4; x++) {
            int adjx = i + dRow[x];
            int adjy = j + dCol[x];
            if(dfs(adjx, adjy, cnt+1, grid, word)) return true;
        }
        grid[i][j] = word[cnt];
    }

    return false;
}

void solve() {
    vector<vector<char>> grid = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    row = grid.size();
    col = grid[0].size();
    rep0(i, row) {
        rep0(j, col) {
            if(dfs(i, j, 0, grid, word)) {
                put("found");
                return;
            }
        }
    }

    put("not found");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}