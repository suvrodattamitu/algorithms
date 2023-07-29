//https://codeforces.com/problemset/problem/1753/B
//https://www.youtube.com/watch?v=4xCRuLZubbg
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
    ll n, x;
    cin >> n >> x;

    vi arr(n), cnt(n, 0);
    rep0(i, n) {
        get(arr[i]);
        cnt[arr[i]]++;
    }

    rep1(i, x-1) {
        if(cnt[i]%(i+1) == 0) {
            cnt[i+1] += (cnt[i]/(i+1));
            cnt[i] = 0;
        }
    }

    rep1(i, x-1) {
        if(cnt[i] != 0) {
            put("NO");
            return;
        }
    }

    put("YES");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}