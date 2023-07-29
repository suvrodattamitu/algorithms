//https://codeforces.com/problemset/problem/165/B
#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll n, d;
    int i, j, k;
    cin >> n >> d;
    
    ll low = 1, high = 1LL<<45, ans, mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        
        ll sum = 0, t = mid;
        while (t)
        {
            sum += t;
            t /= d;
        }
        
        if (sum >= n) {
            high = mid-1;
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    
    cout << ans << endl;
        
    return 0;
}