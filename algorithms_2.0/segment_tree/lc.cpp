//https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
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
const ll N = 2e4+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class SGTree {
public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4*n + 1);
    }
    
    void build(int idx, int low, int high, map<int, int>& mp) {
        if(low == high) {
            seg[idx] = mp[low];
            return;
        }
        
        int mid = (high + low) / 2;
        build(2*idx+1, low, mid, mp);
        build(2*idx+2, mid+1, high, mp);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    void update(int idx, int low, int high, int i, int val) {
        if(low == high) {
            seg[idx] += val;
            return;
        }

        int mid = (low + high) / 2;
        if(i <= mid) {
            update(2*idx+1, low, mid, i, val);
        } else {
            update(2*idx+2, mid+1, high, i, val);
        }

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int query(int idx, int low, int high, int l, int r) {
        //no overlap
        if(low > r || high < l) return 0;

        //complete overlap
        if(low >= l && high <= r) return seg[idx];

        //partial overlap
        int mid = (low + high) / 2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);

        return left + right;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = len(nums);
        map<int, int> mp;
        for(int num : nums) mp[num+10004]++;

        SGTree st(N);
        st.build(0, 0, N, mp);

        vector<int> ans;
        rep0(i, n) {
            mp[nums[i]]--;
            st.update(0, 0, N, nums[i]+10004, -1);
            int cur = st.query(0, 0, N, 1, nums[i]+10004-1);
            ans.pb(cur);
        }

        return ans;
    }
};