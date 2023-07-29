//https://atcoder.jp/contests/abc279/tasks/abc279_d
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

ll a, b;
// this gives wrong ans
// double f(ll mid) {
//     return (mid * b) + (a/sqrt(1.L * (mid+1)));
// }

void solve() {
    cin >> a >> b;
    
    auto f = [&](ll g) {
        return (g * b) + a / std::sqrt(1.L * (g+1));
    }; 
    
    //if high = a it gives wrong
    ll low = 0, high = a / b + 2, ans = 0;
    while(low <= high) {
        ll mid = (low+high) / 2;
        if(f(mid) < f(mid+1)) {
            high = mid - 1; 
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    
    cout << fixed << setprecision(10);
    put( f(ans) );
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