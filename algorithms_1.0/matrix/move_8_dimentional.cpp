//https://atcoder.jp/contests/abc302/tasks/abc302_b
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H,W;
    cin >> H >> W;
    vector<string>S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int k = 0; k < 8; k++) {
                bool flag = true;
                for(int l = 0; l < 5; l++) {
                    int nx = i+dx[k]*l;
                    int ny = j+dy[k]*l;
                    if(nx >= 0 && nx < H && ny >= 0 && ny < W && "snuke"[l] == S[nx][ny]) {
                        continue;
                    }
                    flag = false;
                }
                if(flag) {
                    for(int l = 0; l < 5; l++) {
                        cout << i+dx[k]*l+1 << " " << j+dy[k]*l+1 << "\n";
                    }
                }
            }
        }
    }
}