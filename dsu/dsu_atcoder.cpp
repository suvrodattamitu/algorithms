//https://atcoder.jp/contests/practice2/tasks/practice2_a
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

int main()
{
    ll n, q;
    cin >> n >> q;
    
    int parent[n+10] = {0}, size[n+10] = {0};
    
    //at first everyone is parent of everyone
    rep0(i, n) parent[i] = i;
    
    ll type, u, v;
    while(q--) {
        cin >> type >> u >> v;
        
        //find if both are in same connected components or not
        if(type) {
            ll a = findParent(u, parent);
            ll b = findParent(v, parent);
            
            if(a == b) {
                put(1);
            }
            
            else put(0);
        } 
        
        //build disjoint set
        else {
            unionNodes(u, v, parent, size);
        }
    }

    return 0;
}