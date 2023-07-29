#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) str.length()
#define lena(arr) arr.size() 
#define pb push_back
const int MOD = 1000000007;

typedef vector<ll> vi;

struct point {
    int weight, position, id;
};

void solve() {
	ll n, m;
	cin >> n >> m;
	
	vector<point> points(m);
	rep0(i, m) {
	    cin >> points[i].position >> points[i].weight;
	    points[i].id = i+1;
	}
	
	sort(points.begin(), points.end(), [] (point a, point b) {
        return a.weight < b.weight;
    });
	
	ll sum = 0;
    rep0(i, m) {
        if(i < 2 * n) sum += points[i].weight;
        else points.pop_back();
    }
    
    sort(points.begin(), points.end(), [] (point a, point b) {
        return a.position < b.position;
    });
    
	put(sum);
    rep0(i, n) {
        cout << points[i].id << ' ' << points[2 * n - i - 1].id << endl;
    }
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