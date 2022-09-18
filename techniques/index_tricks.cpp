//https://www.codechef.com/CCLS2022/problems/NIKNP
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>

using namespace std;
#define ll long long

typedef vector<int> vi;
typedef vector<vi> vvi;

vi v = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7};
vvi p = {{0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

void solve() {
	int N, X, Y; string s;
	cin >> N >> X >> Y >> s;
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		ll cost = X;
		int a = v[s[i - 1] - 'a'], b = v[s[i] - 'a'];
		if (i > 0) cost += a == b ? Y : (abs(p[a][0] - p[b][0]) + abs(p[a][1] - p[b][1]));
		ans += cost;
	}
	printf("%lld\n", ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
		solve();
	}

    return 0;
}