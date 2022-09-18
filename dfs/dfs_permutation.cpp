//https://codeforces.com/problemset/problem/1690/F
//https://www.youtube.com/watch?v=NP37okV7Oi8
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 205;

int vis[N];
vector<int> adj[N];

int n;
string str, str1;

ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

void dfs(int v) {
	if(vis[v]) return;

	vis[v] = 1;
	str1 += str[v];
 
	for(auto u: adj[v]) {
		if(!vis[u]) {
			dfs(u);
		}
	}
}

void solve() {
	cin >> n;
	cin >> str;

	vector<ll> arr(n);

	for(int i = 0; i < n; i++) {
		adj[i].clear();
		vis[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		cin >> arr[i]; arr[i]--;
		adj[i].push_back(arr[i]);
	}
    
    set<ll> st;
	for(int i = 0; i < n; i++) {
		str1 = "";
		if(!vis[i]) {
			dfs(i);
			
			string tmpstr = str1;
            
            ll cnt = 0;
            while(1) {
                rotate(str1.begin(), str1.begin()+1, str1.end());
                cnt++;
                if(str1 == tmpstr) break;
            }
            
            st.insert(cnt);
		}
	}
	
	ll ans=1;
    for(auto &i : st){
        ans = lcm(ans, i);
    }
    cout << ans << endl;
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