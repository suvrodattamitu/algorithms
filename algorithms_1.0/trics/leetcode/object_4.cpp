//https://leetcode.com/problems/design-memory-allocator/description/
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
#define len(x) ((ll)x.size())
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Allocator {
public:
    vi arr;
    Allocator(int n) {
        arr.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        rep0(i, len(arr)) {
            if(arr[i] == 0) {
                ++cnt;
            } else {
                cnt = 0;
            }

            if(cnt == size) {
                while(size > 0) {
                    arr[i] = mID;
                    --i;
                    --size;
                }

                return ++i;
            }
        }

        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        rep0(i, len(arr)) {
            if(arr[i] == mID) {
                arr[i] = 0;
                ++cnt;
            }
        }

        return cnt;
    }
};