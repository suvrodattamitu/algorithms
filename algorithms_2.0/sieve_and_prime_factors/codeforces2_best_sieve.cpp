//https://leetcode.com/contest/weekly-contest-326/problems/closest-prime-numbers-in-range/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
vector<int> min_div(N);

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n == 1 || min_div[n] > m ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    for (int d = 2; d * d < N; ++d) {
        if (min_div[d] == 0) {
            min_div[d] = d;
            for (int i = d * d; i < N; i += d) {
                if (min_div[i] == 0) {
                    min_div[i] = d;
                }
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (min_div[i] == 0) {
            min_div[i] = i;
        }
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}