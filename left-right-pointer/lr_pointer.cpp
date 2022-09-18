//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include<iostream>
#include<vector>
using namespace std;

#define ll long long  

int solve() 
{
	int n, target;
	cin >> n;
	vector<int> nums(n); 
	
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int l = 0, r = nums.size() - 1;
	while(l < r) {
		int num_a = nums[l];
		int num_b = nums[r];
		int sum   = num_a + num_b;
		if(sum > target) {
			r--;
		} else if(sum < target) {
			l++;
		} else {
            return {l , r};
        }
	}

	cout << l << " " << r;
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