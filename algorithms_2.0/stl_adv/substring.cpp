//https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/
#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
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
const ll maxn = 2e5;

class Solution {
public:
    string concatinate(string a, string b) {
        ll n = len(a), m = len(b);

        bool found = a.find(b) != string::npos;
        if(found) return a;

        For(i, max(0LL, n-m), n-1) {
            string str1 = a.substr(i);
            string str2 = b.substr(0, n-i);

            if(str1 == str2) return a.substr(0, i) + b; 
        }

        return a + b;
    }

    string minimumString(string a, string b, string c) {
        vector<string> v, vv;
        v.pb(concatinate(concatinate(a, b), c));
        v.pb(concatinate(concatinate(a, c), b));
        v.pb(concatinate(concatinate(b, a), c));
        v.pb(concatinate(concatinate(b, c), a));
        v.pb(concatinate(concatinate(c, a), b));
        v.pb(concatinate(concatinate(c, b), a));
        
        ll mn = INT_MAX;
        for(string s: v){
            mn = min(mn, len(s));
        }

        for(string s: v){
            if(s.size() == mn) vv.pb(s);
        }

        sort(all(vv));

        return vv[0];
    }
};