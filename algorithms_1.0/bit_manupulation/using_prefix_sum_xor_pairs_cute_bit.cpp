//https://www.codechef.com/problems/BIN_OD
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

void solve() {
    int N, Q; cin >> N >> Q;
    
    ll cnt[60][N+1]; 
    rep0(i, 60) cnt[i][0] = 0;
    
    rep1(i, N) {
        ll X; cin >> X;
        rep0(j, 60) {
            cnt[j][i] = cnt[j][i-1] + ((X&(1ll<<j))?1:0);
        }
    }

    while(Q--) {
        int L1, R1, L2, R2, K; cin >> K >> L1 >> R1 >> L2 >> R2;
        L1--; L2--;
        
        ll c1 = cnt[K][R1] - cnt[K][L1];
        ll c2 = R1 - L1 - c1;
        ll c3 = cnt[K][R2] - cnt[K][L2];
        ll c4 = R2-L2-c3;
        
        ll ans = c1*c4 + c2*c3;
        put(ans);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
	get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}