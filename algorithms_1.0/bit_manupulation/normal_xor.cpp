#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

#define ll long long 

void solve() {
	int x, y;
	cin >> x >> y;

    int z = x^y;

    int a[3];
    a[0]=a[1]=a[2]=2;

    if(x&1) a[0] = x^2;
    if(y&1) a[1] = y^2;
    if(z&1) a[2] = z^2;

    sort(a,a+3);

    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<'\n';
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