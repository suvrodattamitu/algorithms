//https://atcoder.jp/contests/abc217/tasks/abc217_d
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

int findParent(int i, int parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}

void unionNodes(int a, int b, int parent[], int size[], vector<ll>& magnitudes)
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
        magnitudes[parent_a] += magnitudes[parent_b];
    }
    
    else
    {
        size[parent_b]  += size[parent_a];
        parent[parent_a] = parent_b;
        magnitudes[parent_b]+=magnitudes[parent_a];
    }
    
    return;
}

void solve() {
    vector<pair<int,int>> queries;

    int l,q;
    cin>>l>>q;

    vector<int> cuts;

    for(int i=0;i<q;i++){
        int c,x;
        cin>>c>>x;
        queries.push_back({c,x});
        if(c==1){
            cuts.push_back(x);
        }
    }

    cuts.push_back(l);

    sort(cuts.begin(),cuts.end());

    int n=cuts.size();
    vector<ll> magnitudes(n);

    magnitudes[0]=cuts[0];
    for(int i=1;i<n;i++){
        magnitudes[i]=cuts[i]-cuts[i-1];
    }

    int parent[n+10] = {0}, size[n+10] = {0};
    //at first everyone is parent of everyone
    rep0(i, n) parent[i] = i;

    vector<ll> ans;

    for(int i=q-1;i>=0;i--){
        int c=queries[i].first;
        int x=queries[i].second;

        int left = upper_bound(cuts.begin(),cuts.end(),x-1)-cuts.begin();
        int right = upper_bound(cuts.begin(),cuts.end(),x)-cuts.begin();

        if(c == 1) {
            unionNodes(left, right, parent, size, magnitudes);
        } else {
            ans.push_back(magnitudes[findParent(right, parent)]);
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
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