//https://atcoder.jp/contests/abc303/tasks/abc303_d
#include <bits/stdc++.h>
#define int long long

#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
using namespace std;
const int N=3e5+1;
int dp[N][2];
int x,y,z;
string s;
int n;

int sol(int i, int j){
    if(i >= n) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int chng = 0;
    int nochng = 0;
    if(j == 0 && s[i] == 'a') {
        chng = z+y+sol(i+1,1);
        nochng = x+sol(i+1,0);
    }
    
    else if(j == 0 && s[i] == 'A') {
        chng = z+x+sol(i+1,1);
        nochng = y+sol(i+1,0);
    }
    
    else if(j == 1 && s[i] == 'A') {
        chng = z+y+sol(i+1,0);
        nochng = x+sol(i+1,1);
    }
    
    else if(j == 1 && s[i] == 'a') {
        chng = z+x+sol(i+1,0);
        nochng = y+sol(i+1,1);
    }
    
    return dp[i][j] = min(chng, nochng);
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>x>>y>>z;
    cin>>s;
    n=s.size();
    int res=sol(0,0);
    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}