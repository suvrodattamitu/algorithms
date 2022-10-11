//https://www.codechef.com/submit/EQUIVALENT
#include <bits/stdc++.h>
using namespace std;

vector<int>v(1e6+1,0);

void perform() {
    for(int i = 0; i < 1e6+1; i++){
       v[i] = i;
    }

    for(int i = 2; i < 1e3+1; i++) {
        for(int j = i; j < 1e6+1; j *= i) {
          v[j] = min(i, v[j]);
        }
    }
}

int main() {
	int t;
	
	cin >> t;
	perform();
	
	while(t--) {
	    int a, b;
	    cin >> a >> b;
	    if(v[a] == v[b]) {
	        cout << "YES";
	    }
	    
	    else {
	        cout << "NO";
	    }
	    
	    cout << endl;
	}
	return 0;
}
