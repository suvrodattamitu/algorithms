//https://codeforces.com/problemset/problem/1819/A
#include <bits/stdc++.h>
using namespace std;

int Mex(vector<int> a) {
  sort(a.begin(), a.end());
  if (a[0] > 0) return 0;
  for (int i = 1; i < (int) a.size(); i++) {
    if (a[i] > a[i - 1] + 1) {
      return a[i - 1] + 1;
    }
  }
  return a.back() + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m = Mex(a);
    int L = n + 1;
    int R = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == m + 1) {
        L = min(L, i);
        R = max(R, i);
      }
    }
    if (R == -1) {
      cout << (m == n ? "No" : "Yes") << '\n';
    } else {
      for (int i = L; i <= R; i++) {
        a[i] = m;
      }
      cout << (Mex(a) == m + 1 ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
