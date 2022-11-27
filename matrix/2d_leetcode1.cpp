//https://leetcode.com/contest/biweekly-contest-92/problems/difference-between-ones-and-zeros-in-row-and-column/
#include<bits/stdc++.h>
#ifdef xay5421
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
using ULL=unsigned long long;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
    	int n=SZ(a);
    	int m=SZ(a[0]);
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>vi(n),vj(m);
        
        rep(i,0,n-1) {
        	rep(j,0,m-1) {
        		vi[i] += a[i][j]?1:-1;
        		vj[j] += a[i][j]?1:-1;
        	}
        }

        rep(i,0,n-1){
        	rep(j,0,m-1){
        		ans[i][j] = vi[i]+vj[j];
        	}
        }
        return ans;
    }
};