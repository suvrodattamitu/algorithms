#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map <int,int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0) {
                    x /= j;
                    a[j]++;
                }
            }
            if (x != 1) {
                a[x]++;
            }
        }

        int res = 0, rem = 0;

        for (pair <int, int> p : a) {
            int num = p.first;
            int cnt = p.second;
            res += cnt / 2;
            rem += cnt % 2;
        }

        res += rem / 3;
        cout << res << '\n';
    }

    return 0;
}