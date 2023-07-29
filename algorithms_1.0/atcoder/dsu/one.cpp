//https://atcoder.jp/contests/abc238/tasks/abc238_e
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

int findParent(int i,int parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}
    
void unionNodes(int a, int b, int parent[], int size[])
//to merge the connected components of nodes a and b
{
    int parent_a = findParent(a, parent);
    int parent_b = findParent(b, parent);
    
    if(parent_a == parent_b) // they are already friends
        return;
        
    if(size[parent_a] >= size[parent_b])//the larger connected component eats up the smaller one
    {
        size[parent_a]     += size[parent_b];
        parent[parent_b]   = parent_a;
    }
    
    else
    {
        size[parent_b]  += size[parent_a];
        parent[parent_a] = parent_b;
    }
    
    return;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    
    int parent[n+1], size[n+1];
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    ll l, r;
    while(q--) {
        cin >> l >> r; --l;
        unionNodes(l, r, parent, size);
    }
    
    int parent_a = findParent(0, parent);
    int parent_b = findParent(n, parent);
    
    string ans = "No";
	if(parent_a == parent_b) ans = "Yes";
	put(ans);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	//get(tc);
	while (tc--) {
		solve();
	}
}