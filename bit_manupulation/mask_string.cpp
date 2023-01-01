//https://leetcode.com/contest/weekly-contest-324/problems/count-pairs-of-similar-strings/
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

class Solution {
public:
    int similarPairs(vector<string>& words) {
        ll ans = 0;
        unordered_map<int, int> freq; 
        for (auto& word : words) {
            int mask = 0; 
            for (auto& ch : word) {
                mask |= (1<<ch-'a'); 
            }
            ans += freq[mask]++;
        }
        return ans;         
    }
};