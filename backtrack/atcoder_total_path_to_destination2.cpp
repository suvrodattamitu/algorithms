//https://atcoder.jp/contests/abc293/tasks/abc293_c

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,ans,a[20][20];
multiset<int> s;
void dfs(int x,int y)
{
	if(y>m||x>n||s.count(a[x][y]))
		return;
	if(x==n&&y==m) {
		ans++;
		return;
	}
	s.insert(a[x][y]);
	dfs(x+1,y);
	dfs(x,y+1);
	s.erase(s.find(a[x][y]));
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			a[i][l]=read();
	dfs(1,1);
	cout<<ans;
	return 0;
}