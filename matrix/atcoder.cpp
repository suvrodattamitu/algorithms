//https://atcoder.jp/contests/abc275/tasks/abc275_c
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 1000000007;
const int N = 1e5+10;
typedef vector<ll> vi;

vector<string> A(9);
bool is_valid(int x, int y) {
    return (0 <= x && x <= 8) && (0 <= y && y <= 8) && A[y][x] == '#';
}

void solve() {
    for(auto &v : A) cin >> v;
    
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int dx = 1; dx < 9; dx++) {
                for (int dy = 0; dy < 9; dy++) {
                    int i2 = i + dx, j2 = j + dy;
                    int i3 = i2 - dy, j3 = j2 + dx;
                    int i4 = i3 - dx, j4 = j3 - dy;
                    ans += is_valid(i, j) && is_valid(i2, j2) && is_valid(i3, j3) && is_valid(i4, j4);
                }
            }
        }
    }
    
    put(ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
//	get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}