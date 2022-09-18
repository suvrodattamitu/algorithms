//https://codeforces.com/contest/1697/problem/C
//https://www.youtube.com/watch?v=Yh2lTQBs22E
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    queue<int>q[3];
    for(int i = 0; i < n; i++) {
        q[s[i] - 'a'].push(i);
    }
    
    for(char c:t) {
        if(c == 'a') {
            if(q[0].empty() || (!q[1].empty() && q[1].front() < q[0].front()) || (!q[2].empty() && q[2].front() < q[0].front()) ) {
                cout << "NO" << endl;
                return;
            }
            
            q[0].pop();
        }
        
        else if(c == 'b') {
			if(q[1].empty() || (!q[2].empty() && q[2].front() < q[1].front())) {
				cout << "NO\n";
				return;
			}
			q[1].pop();
		}
		
		else {
			if(q[2].empty() || (!q[0].empty() && q[0].front() < q[2].front())) {
				cout << "NO\n";
				return;
			}
			q[2].pop();
		} 
    }
    
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}