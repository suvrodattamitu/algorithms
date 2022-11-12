//try this in bfs and dfs
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 1000000007;
const int N = 1e5+10;
typedef vector<ll> vi;

int color[110];
bool bfs(int src, vector<vector<int>>& graph) {
    queue<int> q;

    q.push(src);
    color[src] = -1;

    while(!q.empty()) {
        src = q.front();
        q.pop();

        for(auto v : graph[src]) {
            if(!color[v]) {
                q.push(v);
                color[v] = -1*color[src];
            }

            //if src and cur node both has same color
            else if(color[v] == color[src]) {
                return false;
            }
        }
    }

    return true;
}

ll solve() {
    vector<vector<int>> graph;
    ll n = graph.size();

    int ans = 1;
    for(int i = 0; i < n; i++) {
        if(!color[i]){
            ans &= bfs(i, graph);
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}