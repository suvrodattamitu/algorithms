// https://atcoder.jp/contests/abc282/tasks/abc282_e
#include<bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

#define int long long 

struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};

vector<mod_int> factorial;
void prepare_factorials(int maximum) {
	factorial.resize(maximum + 1);
	factorial[0] = 1;

	for (int i = 1; i <= maximum; i++) {
		factorial[i] = i * factorial[i - 1];
	}
}

int findParent(int i,int parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}

void unionNodes(int a,int b,int parent[],int size[])
//to merge the connected components of nodes a and b
{
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}

void solve() {
    int n;
    cin >> n >> MOD;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<array<int, 3>> e;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            mod_int temp1 = a[i], temp2 = a[j];
            temp1 = temp1.pow(a[j]);
            temp2 = temp2.pow(a[i]);
            temp1 += temp2;
            
            int val = (int)temp1;
            e.push_back({val,i,j});
        }
    }
    
    sort(e.rbegin(), e.rend());
    
    int parent[n+1], size[n+1];
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    int ans = 0;
    //for(auto [w, a, b] : e) {
    for(int i = 0; i < (int)e.size(); i++) {
        auto [w,a,b] = e[i];
        if(findParent(a, parent) == findParent(b, parent)) { 
           continue;
        }
        
        unionNodes(a, b, parent, size);
        ans += w;
    }
    
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    //cin >> tc;

    while(tc--) {
        solve();
    }
    
    return 0;
}