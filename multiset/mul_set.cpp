//https://codeforces.com/contest/1642/problem/C
//first multi set problem solved by me, yo , yes, yoa

#include<iostream>
#include<set>
using namespace std;

#define ll long long  

void solve() 
{
	ll n, x;
	cin >> n >> x;
	
	ll arr[n];
	multiset<ll> ms;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		ms.insert(arr[i]);
	}

	sort(arr, arr+n);

	for(int i = 0; i < n; i++) {
        if(ms.find(arr[i]) != ms.end()) {
        	ll val = (arr[i] * x);
    		if(ms.find(val) != ms.end())
    		{
    			ms.erase(ms.find(val));
    			ms.erase(ms.find(arr[i]));
    		}
        }
	}

	cout << ms.size() << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) 
	{
        solve();
    }

    return 0;
}