//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

int dp[105];
int rec(vector<int> &price, int n) {
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int ans = 0;
	for(int len_to_cut = 1; len_to_cut <= price.size(); len_to_cut++) {
		if(n-len_to_cut >= 0)
			ans = max(ans, price[len_to_cut-1] + rec(price, n-len_to_cut));
	}
	return dp[n] = ans;
}

int cutRod(vector<int> &price, int n)
{
	memset(dp, -1, sizeof(dp));
	return rec(price, n);
}
