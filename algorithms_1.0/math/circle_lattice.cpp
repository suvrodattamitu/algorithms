//math problem
//https://leetcode.com/problems/count-lattice-points-inside-a-circle/
//https://www.youtube.com/watch?v=RwlBBXH-0PY
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
	vector<vector<int>> circles;//2d array
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        circles[i].push_back(x);
    }

    set<pair<int,int>> st;
    for(int c = 0; c < circles.size(); c++) {
        int x = circles[c][0];
        int y = circles[c][1];
        int r = circles[c][2];

        for(int i = x-r; i <= x+r; i++) {
            for(int j = y-r; j <= y+r; j++) {
                /*
                    to be a circle the equation, x*x + y*y = r*r, should satisfy
                */
                if((i-x)*(i-x) + (j-y)*(j-y) <= r*r) {
                    st.insert({i,j});
                }
            }
        } 
    }

    cout << st.size() << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	//cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}