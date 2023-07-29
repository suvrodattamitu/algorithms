//https://codeforces.com/contest/1807/problem/E
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pb push_back
#define si(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int qry(int x){
    cout << "? " << x << " ";
    for(int i=1; i<=x; i++) cout << i << " ";
    cout << endl;
    int k;
    cin >> k;
    return k;
}

const int N = 200000;

ll p[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        p[i] += p[i-1];
    }
    int l = 1, r = n, prv = n;
    while(l <= r) {
        int mid = (l+r)/2;
        if(qry(mid) != p[mid]){
            r = mid - 1;
            prv = mid;
        }
        else l = mid + 1;
    }
    cout << "! " << prv << endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}