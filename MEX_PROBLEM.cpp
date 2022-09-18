//https://www.codechef.com/submit/KMEX
#include<iostream>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
int n,m,k;
int f[501];
void solve(){
	cin >> n >> m >> k;
	for(int i=0; i<=n ;i++) f[i]=0;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;f[x]++;
	}
	for(int i=0; i<k ;i++){
		if(f[i]==0){
			cout << "NO\n";
			return;
		}
	}
	if(m+f[k]>n || m<k) cout << "NO\n";
	else cout << "YES\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}