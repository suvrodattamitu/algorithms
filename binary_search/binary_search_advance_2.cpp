//https://codeforces.com/contest/1760/problem/F
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

ll n, c, d;

// bool check(long long k){
//     k++;
//     int idx = 0;
//     long long cur = 0;
//     for(int i = 0 ;i < d;i++){
//         if((long long)idx == k) idx = 0;
//         if(idx < n) cur += arr[idx];
//         idx++;
//     }
//     if(cur >= c)
//         return true;
//     return false;
// }

int check(vector<ll>& arr, ll mid) {
    ll tot = 0;
    rep0(i, d) {
        if((i%(mid+1)) < n) {
            tot += arr[i%(mid+1)];
        }
    }
    
    return (tot >= c);
}

void solve() {
    cin >> n >> c >> d;
    
    vi arr(n);
    cin >> arr;
    
    sort(all(arr), greater<ll>());
    
    ll low = 0, high = d + 1, ans = -1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(check(arr, mid)) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    
    if(ans == -1) {
        put("Impossible");
    } else if(ans == d + 1) {
        put("Infinity");
    } else {
        put(ans);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc;
	get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}