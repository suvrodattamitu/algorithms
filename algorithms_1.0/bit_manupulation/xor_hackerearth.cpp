//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/count-pairs-13-c27240a8/editorial/
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define F first
#define S second
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mpp;
typedef pair<ll,ll> pll;

int findMSB(int n){
    int msb=0;
    while(n){
        n/=2;
        msb++;
    }
    return msb;
}

void solve() 
{  
    ll n; 
	cin>>n;

    vector<int>bits(32,0);
    ll total = (n*(n-1LL))/2LL;
    for(int i = 0; i < n; i++) {
        int x; 
		cin >> x;
		// it will find msb
        for(int j = 31; j >= 0; j--) { 
            if(x & (1LL << j)) {
                total -= bits[j];
                bits[j]++;
                break;
            }
        }
    }
    cout<<total<<endl;
}

int main() 
{
    ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) 
	{
		solve();
	}

    return 0;
}