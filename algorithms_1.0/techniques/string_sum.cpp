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

void solve() {
	string s;
	cin >> s;

	int p;
	cin >> p;

	int c = 0;

	vector<pair<int, int>> arr;
	for(int i = 0; i < s.length(); i++) {
		arr.emplace_back(s[i]-'a'+1, i);
		c += s[i]-'a'+1;
	}
	
	sort(arr.begin(), arr.end());
	vector<bool> visited(s.size(), true);
	while(c > p) {
	    c -= arr.back().first;
	    visited[arr.back().second] = false;
	    arr.pop_back();
	}
	
	for (int i = 0; i < s.size(); i++){
        if (visited[i]) cout << s[i];
    }
    cout << '\n';
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