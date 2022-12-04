////https://atcoder.jp/contests/abc177/tasks/abc177_d
#include<bits/stdc++.h>
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
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll N = 1e5+10;
typedef vector<ll> vi;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

ll findParent(ll i, ll parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}

void unionNodes(ll a, ll b, ll parent[], ll size[])
//to merge the connected components of nodes a and b
{
    ll parent_a = findParent(a, parent);
    ll parent_b = findParent(b, parent);
    
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
    ll n, k;
    cin >> n >> k;

    ll parent[n]={0}, size[n]={0};
    rep0(i, n) {
        parent[i] = i;
        size[i] = 1;
    }

    ll x, y, mx = 1;
    // maximum component size 
    while(k--) {
        cin >> x >> y;
        --x, --y;
        unionNodes(x, y, parent, size);

        ll par = findParent(x, parent);
        mx = max(mx, size[par]);
    }

    // rep0(i, n) {  or do this
    //     ll par = findParent(i, parent);
    //     mx = max(mx, size[par]);
    // }

    put(mx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}