//https://atcoder.jp/contests/abc279/tasks/abc279_f
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
const ll MX = 300005;
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
    
    if(parent_a == parent_b)
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
    
    ll parent[n+q] = {0}, size[n+q] = {0}, content[n+q] = {0}, belong[n+q] = {0};
    
    //at first everyone is parent of everyone
    for(ll i = 1; i <= n+q; i++) {
        parent[i]  = i;
        content[i] = i;
        belong[i]  = i;
    }

    ll type, x, y, k = n;
    while(q--) {
        get(type);

        if(type == 3) {
            get(x);
            //Report the number of the box that contains ball X
            int ans = findParent(x, parent);
            put(belong[ans]);
        }
        
        else if(type == 1) {
            cin >> x >> y;
            //Put all contents of box Y into box X
            
            if (content[y] == -1) {
                continue;
            } else if (content[x] == -1) {
                content[x] = content[y];
                content[y] = -1;
                belong[content[x]] = x;
            } else {
                unionNodes(content[x], content[y], parent, size);
                content[y] = -1;
            }
        }
        
        else if(type == 2) {
            get(x);
            // Put ball k+1 into box X
            k += 1;
            if (content[x] == -1) {
                content[x]  = k;
                belong[k] = x;
            } else {
                unionNodes(content[x], k, parent, size);
            }
        }
    }
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