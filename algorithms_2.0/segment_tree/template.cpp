#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define spaced(n) (cout << n << " ")
#define get(n) (cin >> n);
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

void out(){cout << '\n';}
template<class T>void out(const T& a){cout << a << '\n';}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){cout << head << ' ';out(tail...);}

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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...);
#endif

class SGTree {
public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4*n + 1);
    }
    
    void build(int idx, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }
        
        int mid = (high + low) / 2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int low, int high, int l, int r, vector<int>& arr) {
        //no overlap
        if(low > r || high < l) return INT_MAX;
        
        //complete overlap
        if(low >= l && high <= r) return seg[idx];
        
        //partial overlap
        int mid = (high + low) / 2;
        int leftRes = query(2*idx+1, low, mid, l, r, arr);
        int rightRes = query(2*idx+2, mid+1, high, l, r, arr);
        return min(leftRes, rightRes);
    }
    
    void update(int idx, int low, int high, int i, int val, vector<int>& arr) {
        if(low == high) {
            seg[idx] = val;
        }
        
        int mid = (high + low) / 2;
        if(i <= mid) {
            build(2*idx+1, low, mid, arr);
        } else {
            build(2*idx+2, mid+1, high, arr);
        }
        
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }
};

void solve() {
   ll n;
   get(n);
   
   vector<int> arr(n+1);
   rep0(i, n) {
       get(arr[i]);
   }
   
   SGTree sg(n);
   sg.build(0, 0, n-1, arr);
   
   //cout << seg[0] << endl; // checking segemnt build is correct by checking root node
   
   ll q;
   get(q);
   
   int type, l, r, idx, val;
   while(q--) {
       get(type);
       
       if(type == 1) { //get from left - right
           get2(l, r); --l, --r;
           ll ans = sg.query(0, 0, n-1, l, r, arr);
           put(ans);
       } else {
           get2(idx, val); --idx;
           arr[idx] = val;
           sg.update(0, 0, n-1, idx, val, arr);
       }
   }
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	//get(tc);
	while (tc--) {
		solve();
	}
}
