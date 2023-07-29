//https://codeforces.com/problemset/problem/1732/D1
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll tc;
	get(tc);
	
	map<ll, ll> mp;
    map<ll, bool> visited;
	while(tc--) {
	    char ch;
        get(ch);
        
        ll k;
        get(k);
        
        if(ch == '+') {
            visited[k] = 1;
        } else {
            ll cur_val = mp[k] + k;
            while(visited[cur_val]) {
                mp[k]  = cur_val;
                cur_val += k;
            }
            
            put(cur_val);
        }
	}

    return 0;
}