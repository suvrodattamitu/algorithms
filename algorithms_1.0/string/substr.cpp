//https://codeforces.com/contest/1703/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
	int n;
	cin >> n;

	string str;
	map<string, int> mp;
	vector<string> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> str;
		mp[str]++;
		arr[i] = str;
	}

	for(int i = 0; i < n; i++) {
		string tmp = arr[i];
		mp[tmp]--;
		int ok = 0;
		for(int j = 0; j + 1 < tmp.length(); j++) {
			if(mp[tmp.substr(0, j+1)] && mp[tmp.substr(j+1, tmp.length()-j-1)]) {
				ok = 1;
			}
		}

		cout << ok;
		mp[tmp]++;
	}

	cout << endl;
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