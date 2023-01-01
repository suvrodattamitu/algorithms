#include<bits/stdc++.h>
using namespace std;

//union_find_tree
struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

int main(){
	int N,Q; cin >> N >> Q;
	union_find tree(N+1);
	while(Q--){
		int l,r; cin >> l >> r;
		tree.unite(l-1,r);
	}
	string ans = "No";
	if(tree.same(0,N)) ans = "Yes";
	cout << ans << endl;
}