//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
//https://cses.fi/problemset/task/1622

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

typedef vector<ll> vi;

set<string> ans;

void backtrack(string a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
        ans.insert(a);
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            backtrack(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 

void solve() {
    string str;
    get(str);
    backtrack(str, 0, str.size()-1);
    put(lena(ans));
    for(string str : ans) {
        put(str);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	//cin >> tc;

    while(tc--) {
		solve();
	}

    return 0;
}