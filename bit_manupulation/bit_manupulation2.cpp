//https://codeforces.com/contest/1688/problem/B 
//first bit manupulation problem solved by me, yes :)
#include<iostream>
using namespace std;

#define ll long long  

void solve() 
{
	ll x;
	cin >> x;

	int cnt[32], cnter = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int j = 0; j < 32; j++) 
	{
		if(1 << j & x) { 
			cnt[j]++;
			if(cnt[j]) {
			    ++cnter;
			}
		}
	}
    
    int cnt1[32], found1 = 0, found0 = 0;
	memset(cnt1, 0, sizeof(cnt1));
	for(int j = 0; j < 32; j++) 
	{
		if(cnt[j] == 1 && !found1) 
		{
		    cnt1[j] = 1;
		    found1 = 1;
		}
		
		else if(cnter == 1) 
		{ 
    		if(cnt[j] == 0 && !found0) 
    		{
    		    cnt1[j] = 1;
    		    found0 = 1;
    		}
    		
    		else if(cnt[j] == 1 && !found0) 
    		{
    		    cnt1[j] = 0;
    		    found0 = 1;
    		}
    		
    		if(found0 && found1) 
    		{
    		    break;
    		}
		}
	}
	
	ll sum = 0;
	for(int j = 0; j < 32; j++) 
	{
	    if(j == 0 && cnt1[j]) 
	    {
			sum += 1;
		} else if(cnt1[j]) 
		{
		    sum += (1<<j);
		}
	}

	cout << sum << endl;
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