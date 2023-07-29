//https://codeforces.com/contest/1700/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int cmp(string a, string b)
{
	int i, l = a.size();
 
	if(a.size() > b.size())
	{
		return 1;
	}
	if(a.size() < b.size())
	{
		return -1;
	}
	else
	{
		for(i=0; i<l; i++)
		{
			if(a[i] > b[i])
				return 1;
			if(b[i] > a[i])
				return -1;
		}
		return 0;
	}
}

string strsub(string x, string y)
{
	string a;
 
	int i, j, flag=0, l, ll2;
 
	if(cmp(x, y) == 0)
	{
		return "0";
	}
 
	if(cmp(x, y) == -1)
	{
		flag = 1;
		swap(x, y);
	}
 
	l = x.size(), ll2 = y.size();
 
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
 
	for(i=ll2; i<l; i++)
	{
		y += "0";
	}
 
	for(i=0; i<l; i++)
	{
		if(x[i] < y[i])
		{
			j = i+1;
			while(x[j] == '0' && j < l)
			{
				x[j] = '9';
				j++;
			}
			x[j]--;
			x[i] += 10;
		}
		a += (x[i] - y[i]) % 10 + '0';
	}
 
	while(a[l-1] == '0')
	{
		a.erase(a.end()-1);
		l--;
	}
 
	if(flag)
	{
		a += "-";
	}
 
	reverse(a.begin(), a.end());
	return a;
}

int solve() 
{
    ll len; string n;
    cin >> len >> n;

    string str = "";
    if(n[0] == '9') {
        for(int i = 0; i <= len; i++) {
            str += "1";
        }
    } else {
        for(int i = 0; i < len; i++) {
            str += "9";
        }
    }
    
    cout << strsub(str, n) << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}