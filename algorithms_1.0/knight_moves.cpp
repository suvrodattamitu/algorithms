//https://www.codechef.com/submit/KNIGHTATTACK
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int board[8][8];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void solve()
{
    int x1, x2, y1, y2;
    memset(board, 0, sizeof(board));

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    x1--;
    y1--;
    x2--;
    y2--;

    board[x1][y1] = 1;
    board[x2][y2] = 1;

    set<pair<int, int>> s;

    for (int i = 0; i < 8; i++)
    {
        int nx = x1 + dx[i];
        int ny = y1 + dy[i];

        if (nx < 8 && nx >= 0 && ny >= 0 && ny < 8 && board[nx][ny] != 1)
        {
            s.insert({nx, ny});
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int nx = x2 + dx[i];
        int ny = y2 + dy[i];

        if (nx < 8 && nx >= 0 && ny >= 0 && ny < 8 && board[nx][ny] != 1)
        {
            if (s.find({nx, ny}) != s.end())
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
