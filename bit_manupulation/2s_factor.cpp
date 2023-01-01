//https://codeforces.com/contest/1762/problem/B
#include <bits/stdc++.h>
using namespace std;

void testCase() {
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int lg = 31 - __builtin_clz(x);
    ans.push_back({i + 1, (1 << (lg + 1)) - x});
  }
  cout << ans.size() << "\n";
  for (auto [a, b] : ans) cout << a << " " << b << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
}