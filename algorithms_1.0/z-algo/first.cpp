//https://atcoder.jp/contests/abc284/tasks/abc284_f
#include<bits/stdc++.h>
using namespace std;

int N;
string T;

template <class T> vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

int main()
{
	cin >> N >> T;
	string revT = T;
	
	reverse(revT.begin(), revT.end());
	
	vector<int>L = z_algorithm(T + revT); 
	vector<int>R = z_algorithm(revT + T);
	
	for(int i = 0; i <= N; i++)
	{
		if(L[2*N+N-i] < i) continue;
		if(R[2*N+i] < N-i) continue;
		
		string S = T.substr(i, N);
		reverse(S.begin(),S.end());
		
		cout << S << endl << i <<endl;
		return 0;
	}
	
	cout<<-1<<endl;
}

/*
405
*/