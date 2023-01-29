//https://atcoder.jp/contests/abc287/tasks/abc287_e
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

struct TrieNode{
    TrieNode* child[26];
    ll freq;
};

TrieNode* newNode() {
    TrieNode* temp = new TrieNode;
    temp->freq = 0;
    rep0(i, 26) {
        temp->child[i] = NULL;
    }
    return temp;
}

void insert(TrieNode* root, string &s) {
    TrieNode* itr = root;
    rep0(i, len(s)) {
        int id = s[i]-'a';
        if (!itr -> child[id])
            itr -> child[id] = newNode();
        itr = itr -> child[id];
        itr->freq++;
        debug(itr->freq);
    }
}

void remove(TrieNode* root, string &s) {
    TrieNode* itr = root;
    rep0(i, len(s)) {
        itr = itr -> child[s[i]-'a'];
        itr->freq--;
    }
}

ll find(TrieNode* root, string &s) {
    TrieNode* itr = root;
    ll ans = 0;
    rep0(i, len(s)) {
        int id = s[i]-'a';
        if (!itr -> child[id])
            break;
        itr = itr -> child[id];
        if(itr->freq > 0)
            ans++;
        else
            break;
    }
    return ans;
}

void solve() {
    ll n;
    get(n);

    vector<string> str(n);

    TrieNode* root = newNode();
    rep0(i, n) {
        get(str[i]);
        insert(root, str[i]);
    }

    rep0(i, n) {
        remove(root, str[i]);
        put(find(root,str[i]));
        insert(root,str[i]);
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