//https://www.codechef.com/submit-v2/MAKEQUAL
#include <iostream>
using namespace std;

#define ull unsigned long long

void solve() 
{
    ull a[3];
    cin >> a[0] >> a[1] >> a[2];

    for (int i = 0; i < 31; i++) {
        if (a[0] == a[1] && a[1] == a[2]) {
            cout << "YES\n";
            return;
        }
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            cnt += !!(a[j] & (1ll << i));
        }
        if (cnt == 0 || cnt == 3) {
            cout << "NO\n";
            return;
        }
        if (cnt == 1) {
            for (int j = 0; j < 3; j++) {
                if (a[j] & (1ll << i)) a[j] += (1ll << i);
            }
        } else if (cnt == 2) {
            for (int j = 0; j < 3; j++) {
                if (a[j] & (1ll << i)) continue;
                a[j] += (1ll << i);
            }
        }
    }
    cout << "NO\n";
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}