#include <iostream>
#include <map>
#include <set>
using namespace std;

#define ll long long

void solve() 
{
    string s;
    int x;

    cin >> s >> x;

    map<string, int> mp;
    set<string> st;
    
    while(mp[s] <= 1) {
        //actual time after adding x minutes
        int hh = (s[0] - '0') * 10 + (s[1] - '0');
        int mm = (s[3] - '0') * 10 + (s[4] - '0');
        
        //convert full time to minutes
        int cur = hh * 60 + mm;
		cur += x;
		
		//convert hour minutes
		hh = cur / 60;
		hh %= 24;
		mm = cur % 60;
		
        //if smaller than 10 balance them with leading 0
        if(hh < 10) {
            s[0] = '0';
            s[1] = hh + '0';
        } else {
            s[0] = hh/10 + '0';
            s[1] = hh%10 + '0';
        }

        if(mm < 10) {
            s[3] = '0';
            s[4] = mm + '0';
        } else {
            s[3] = mm/10 + '0';
            s[4] = mm%10 + '0';
        }

        string t = s;
        reverse(t.begin(), t.end());
        if(t == s) {
            st.insert(s);
        }

        ++mp[s];
    }
    
    cout << st.size() << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}