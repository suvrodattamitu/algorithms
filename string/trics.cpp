//https://www.codechef.com/problems-old/COPYPUSH
//dont build rather break string

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (s.size())
    {
        if (s.size() % 2) {
            s.pop_back();
        } else {
            if (s.substr(0, s.size() / 2) != s.substr(s.size() / 2, s.size() / 2)) {
                cout << "NO\n";
                return;
            }
            s = s.substr(0, s.size() / 2);
        }
    }
    cout << "YES\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
}