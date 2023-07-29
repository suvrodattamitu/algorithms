//https://atcoder.jp/contests/abc285/tasks/abc285_f
#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}

struct nd{
	int l[2], r[2], num, tag;
};

nd tr[N<<2];
char s[N];
int n,q;
int cnt[50];
nd merge(nd x, nd y) {
	nd z;
	z.num = x.num + y.num;
	z.tag = x.tag || y.tag;
	if(x.r[0] > y.l[0]) z.tag = 1;

	if(x.l[1] == x.num && y.r[1] == y.num) {
		if(x.l[0] == y.r[0]) {
			z.l[0] = z.r[0] = x.l[0];
			z.l[1] = z.r[1] = z.num;
		}

		else {
			for(int i = 0; i < 2; ++i) {
				z.l[i] = x.l[i];
				z.r[i] = y.r[i];
			}
		}

		return z;
	}

	for(int i = 0; i < 2; ++i) {
		z.l[i] = x.l[i];
		z.r[i] = y.r[i];
	}

	if(x.l[1] == x.num) {
		if(x.l[0] == y.l[0]) z.l[1] += y.l[1];
	}

	if(y.r[1] == y.num) {
		if(y.r[0] == x.r[0]) z.r[1] += x.r[1];
	}

	return z;
}

void build(int node, int l, int r) {
	if(l == r) {
		tr[node].l[0] = tr[node].r[0] = s[l] - 'a';
		tr[node].l[1] = tr[node].r[1] = 1;
		tr[node].num = 1;
		return;
	}

	int mid = (l+r) / 2;

	build(node*2, l, mid);
	build(node*2+1, mid+1, r);

	tr[node] = merge(tr[node*2], tr[node*2+1]);
}

void upd(int cnt,int l,int r,int x,int y){
	if(l==r){
		tr[cnt].l[0]=tr[cnt].r[0]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)upd(cnt<<1,l,mid,x,y);
	else upd(cnt<<1|1,mid+1,r,x,y);
	tr[cnt]=merge(tr[cnt<<1],tr[cnt<<1|1]);
}

nd query(int cnt,int l,int r,int L,int R){
	if(l>=L&&r<=R)return tr[cnt];
	int mid=(l+r)>>1;
	if(mid>=L&&mid<R)return merge(query(cnt<<1,l,mid,L,R),query(cnt<<1|1,mid+1,r,L,R));
	if(mid>=L)return query(cnt<<1,l,mid,L,R);
	return query(cnt<<1|1,mid+1,r,L,R); 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>(s+1);

	for(int i = 1; i <= n; ++i) {
		cnt[s[i]-'a']++;
	}

	build(1, 1, n);

	cin >> q;
	char c;
	int x, l, r, opt;
	while(q--) {
		cin >> opt;

		if(opt == 1) {
			cin >> x >> c;
            upd(1, 1, n, x, c-'a');
			cnt[s[x]-'a']--;
			cnt[c-'a']++;
			s[x] = c;
		} 

		else {
			cin >> l >> r;
			nd x = query(1, 1, n, l, r);
		//	cout<<x.l[0]<<" ?? "<<x.r[0]<<endl;
		//	cout<<x.l[1]<<" ?? "<<x.r[1]<<endl;
			if(x.tag) cout << "No\n";
			else if(x.l[1] == r-l+1) cout << "Yes\n";
			else {
				int num = r-l+1-x.l[1]-x.r[1];
				for(int i = x.l[0]+1; i < x.r[0]; ++i) num -= cnt[i];
				if(num != 0) cout << "No\n";
				else cout << "Yes\n";
			}
		}
	}

    return 0;
}
