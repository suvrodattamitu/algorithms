//https://codeforces.com/contest/1602/problem/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long  

void solve() {
	int n;
	cin >> n;

	int arr[n], cnt[32];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		for(int j = 0; j < 32; j++) {
			if(1 << j & arr[i]) { 
				cnt[j]++;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		bool works = true;
		for(int j = 0; j < 32; j++) 
			if(cnt[j]%i != 0) works = false;
		if(works) cout << i << " ";
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