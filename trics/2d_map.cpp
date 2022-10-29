#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define putln(n) (cout << n << " ")
#define get(n) (cin >> n)
#define lens(str) str.length()
#define lena(arr) arr.size() 
#define pb push_back

typedef vector<ll> vi;

void solve() {
	ll n;
	get(n);

    vi sum(3, 0);
    
    map<int, map<string, int>> mp;
    
    string str[3][n];
    rep0(j, 3) {
    	rep0(i, n) {
    	  get(str[j][i]);
    	  mp[j][str[j][i]]++;
    	}
    }
    
    rep0(j, 3) {
    	rep0(i, n) {
    	   if(j == 0) {
    	       if(mp[0][str[j][i]] && mp[1][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[1][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	       }
    	       
    	       else if(mp[0][str[j][i]] && mp[1][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[1][str[j][i]] = 0;
    	           sum[0] += 1; sum[1] += 1;
    	       }
    	       
    	       else if(mp[0][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	           sum[0] += 1; sum[2] += 1;
    	       }
    	       
    	       else if(mp[0][str[j][i]]) {
    	           mp[0][str[j][i]] = 0;
    	           sum[0] += 3;
    	       }
    	   }
    	   
    	   if(j == 1) {
    	       if(mp[0][str[j][i]] && mp[1][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[1][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	       }
    	       
    	       else if(mp[0][str[j][i]] && mp[1][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[1][str[j][i]] = 0;
    	           sum[0] += 1; sum[1] += 1;
    	       }
    	       
    	       else if(mp[1][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[1][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	           sum[1] += 1; sum[2] += 1;
    	       }
    	       
    	       else if(mp[1][str[j][i]]) {
    	           mp[1][str[j][i]] = 0;
    	           sum[1] += 3;
    	       }
    	   }
    	   
    	   if(j == 2) {
    	       if(mp[0][str[j][i]] && mp[1][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[1][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	       }
    	       
    	       else if(mp[0][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[0][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	           sum[0] += 1; sum[2] += 1;
    	       }
    	       
    	       else if(mp[1][str[j][i]] && mp[2][str[j][i]]) {
    	           mp[1][str[j][i]] = 0; mp[2][str[j][i]] = 0;
    	           sum[1] += 1; sum[2] += 1;
    	       }
    	       
    	       else if(mp[2][str[j][i]]) {
    	           mp[2][str[j][i]] = 0;
    	           sum[2] += 3;
    	       }
    	   }
    	}
    }
    
    cout << sum[0] << " " << sum[1] << " " << sum[2] << endl;
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