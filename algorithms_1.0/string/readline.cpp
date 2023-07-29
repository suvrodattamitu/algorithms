//https://leetcode.com/contest/weekly-contest-295/problems/apply-discount-to-prices/
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define ll long long  

void solve() 
{
	string sentence = "there are $1 $2 and 5$ candies in the shop";
	string word; 
	int discount = 50;
    
    stringstream sstr(sentence);
        
    string ans = "";
    while (getline(sstr, word, ' ')) {  
        if(is_valid(word)) {
            double val = stod(word.erase(0, 1));
            stringstream buffer;
            buffer << setiosflags(ios::fixed) << setprecision(2) << (val * ((100-discount)/100.0));
            ans += "$" + buffer.str();
        }  else {
            ans += word;
        }

        ans += " ";
    }
    
    ans.erase(ans.length()-1, 1);
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	//cin >> tc;

    while(tc--) 
	{
        solve();
    }

    return 0;
}