//https://atcoder.jp/contests/abc304/tasks/abc304_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))

int main() {
    ll W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    vector<ll> cx, cy;
    int A, B;
    cin >> A;
    for (int i = 0; i < A; i++) {
        int a;
        cin >> a;
        cx.push_back(a);
    }

    cin >> B;
    for (int i = 0; i < B; i++) {
        int b;
        cin >> b;
        cy.push_back(b);
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        int idx1 = lower_bound(cx.begin(), cx.end(), X[i]) - cx.begin();
        int idx2 = lower_bound(cy.begin(), cy.end(), Y[i]) - cy.begin();
        mp[{idx1, idx2}]++;
    }
    
    int ma = 0, mi = 1e9;
    if ((int)mp.size() < (ll)(A+1)*(B+1)) mi = 0;
    
    for (auto pr : mp) {
        ma = max(ma, pr.second);
        mi = min(mi, pr.second);
    }
    
    cout << mi << " " << ma << endl;
    
    return 0;
}