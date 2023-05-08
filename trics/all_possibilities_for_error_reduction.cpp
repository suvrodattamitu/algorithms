//https://mirror.codeforces.com/contest/1823/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, k;
    cin >> n >> k;
    int b ;
    for(int a = 0; a <= n; a ++ ){
        b = n - a;
        if(a * (a - 1) / 2 + b * (b - 1) / 2 == k){
            cout << "YES\n";
            for(int i = 1; i <= n; i ++ ){
                if(i <= a) cout << "-1 ";
                else cout << "1 ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}
