//https://codeforces.com/problemset/problem/234/C
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>	
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>	
#include <stack>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

const int MAXN=100009;
int a[MAXN],i,j,k,n,b[MAXN],c[MAXN],ans;

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[0]=0;
	for (i=1;i<=n;i++) 
	{
		b[i]=b[i-1];
		if (a[i]>=0) ++b[i]; 
	}
	c[n+1]=0;
	for (i=n;i>=1;i--)
	{
		c[i]=c[i+1];
		if (a[i]<=0) ++c[i];
	}
	ans=10000000;
	for (i=1;i<n;i++)
		ans=min(ans,b[i]+c[i+1]);
	printf("%d\n",ans);
	return 0;
}

