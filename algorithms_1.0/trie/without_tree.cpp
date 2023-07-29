#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int N = 5e5 + 10;
const int M = 131;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
int tr[N * 30][30], idx;
int cnt[N * 30];

void insert(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i++){
		int u = s[i] - 'a';
		if(!tr[p][u]) tr[p][u] = ++idx;
		cnt[tr[p][u]]++;
		p = tr[p][u];
	}
}

void erase(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i++){
		int u = s[i] - 'a';
		cnt[tr[p][u]]--;
		p = tr[p][u];
	}
}

ll query(string s){
	int p = 0, res = 0;
	for(int i = 0; i < (int)s.length(); i++){
		int u = s[i] - 'a';
		if(cnt[tr[p][u]] == 0) break;
		res++;
		p = tr[p][u];
	}
	return res;
}

void solve(){
	int n; cin >> n;
	vector<string> ve(n + 1);
	vector<ll> res(n + 1, 0);
	for(int i = 1; i <= n; i++){
		string s; cin >> s;
		insert(s);
		ve[i] = s;
	}
	for(int i = 1; i <= n; i++){
		erase(ve[i]);
		res[i] = query(ve[i]);
		insert(ve[i]);
	}
	for(int i = 1; i <= n; i++) cout << res[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(12);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0 - 0;
}