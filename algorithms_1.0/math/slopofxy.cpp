//math problem
//https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
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
	vector<vector<int>>stockPrices(n);//2d array
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            int x;
            cin >> x;
            stockPrices[i].push_back( x );
        }
    }

    //int n = stockPrices.size();
        
    if(n == 1) { 
        cout << 0;
        return;
    }

    if(n == 2) {
        cout<< 1;
        return;
    }

    /*
    y2-y1/x2-x1 = slope1
    y3-y2/x3-x2 = slope2

    if slope1 = slope2 then all points belong to the same line

    so, y2-y1/x2-x1 = y3-y2/x3-x2
    => (y2-y1)(x3-x2) = (y3-y2)(x2-x1), a new line start from point (x2, y2) if this equality if not true
    */
    sort(stockPrices.begin(),stockPrices.end());

    int cnt = 1;
    for(int i = 2; i < n; i++) {
        ll slope1 = (ll)(stockPrices[i-1][1] - stockPrices[i-2][1]) * (stockPrices[i][0] - stockPrices[i-1][0]);
        ll slope2 = (ll)(stockPrices[i][1] - stockPrices[i-1][1]) * (stockPrices[i-1][0] - stockPrices[i-2][0]);
        if(slope1 != slope2) cnt++;
    }

    cout << cnt;
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