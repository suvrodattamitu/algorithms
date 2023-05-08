//https://atcoder.jp/contests/abc299/tasks/abc299_e
#include<bits/stdc++.h>
using namespace std;

#define int long long
inline int read()
{
	char ch=getchar();int x=0,r=1;
	while(ch<'0'||ch>'9'){if(ch=='-')r=0;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return r?x:-x;
}
int n,m,x,y,k,dis[2010];
bool c[2010];
vector<int> e[2010],f[2010];
queue<int> q;
signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		x=read();y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;++i)c[i]=1;
	k=read();
	for(int i=1;i<=k;++i)
	{
		x=read();y=read();
		for(int i=1;i<=n;++i)dis[i]=-1;
		dis[x]=0;q.push(x);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			if(dis[u] == y) {//1. if there exists an vertex which is exactly y distance away then we will not color it white, it should be black..
			    f[x].push_back(u);
			    continue;
			}
			c[u]=0; //2. we will color it white cz this is not in y distance
			for(int v:e[u])
			{
				if(dis[v]!=-1)continue;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		if(f[x].empty())return puts("No"),0; //3. no vertex found at y distance
	}
	for(int i=1;i<=n;++i)
	{
		if(f[i].empty())continue;
		bool flag=0;
		for(int u:f[i])if(c[u])flag=1; //4. there should be atleast 1 black, cz we guess there already atleast 1 black exists from this i
		if(flag==0)return puts("No"),0;
	}
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%lld",(int)c[i]);
	return 0;
}