//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2498
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
typedef pair<ll, ll> pii;

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

string findParent(string i, map<string, string>& parent)
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}
 
void unionNodes(string a, string b, map<string, string>& parent, map<string, ll>& size)
//to merge the connected components of nodes a and b
{
    string parent_a = findParent(a, parent);
    string parent_b = findParent(b, parent);
    
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
    ll f;
    get(f);
    
    map<string, string> parent; 
    map<string, ll> size;
    string a, b;
    while(f--) {
        cin >> a >> b;

        if(parent.find(a) == parent.end()) {
            parent[a] = a; 
            size[a] = 1;
        }
        
        if(parent.find(b) == parent.end()) {
            parent[b] = b; 
            size[b] = 1;
        }

        unionNodes(a, b, parent, size);
        ll sz = size[findParent(a, parent)];
        put(sz);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}