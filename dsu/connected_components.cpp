//https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int findParent(int i,int parent[])
    //function to find the connected component that the ith node belongs to
    {
        if(parent[parent[i]] != parent[i])
            parent[i] = findParent(parent[i], parent);
        return parent[i];
    }

    void unionNodes(int a, int b, int parent[], int size[])
    //to merge the connected components of nodes a and b
    {
        int parent_a = findParent(a, parent);
        int parent_b = findParent(b, parent);
        
        if(parent_a == parent_b) // they are already friends
            return;
            
        if(size[parent_a] >= size[parent_b])//the larger connected component eats up the smaller one
        {
            size[parent_a]     += size[parent_b];
            parent[parent_b]   = parent_a;
        }
        
        else
        {
            size[parent_b]  += size[parent_a];
            parent[parent_a] = parent_b;
        }
        
        return;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int parent[N] = {0}, size[N] = {0};

        //number can be negetive that's why we need to make component using index
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        int mx = 0;
        rep0(i, lena(nums)) {
            int cur = nums[i];
            if(mp.count(cur)) {
                continue;
            }
        
            mp[cur] = i;
            
            if(mp.count(cur-1)) {
                unionNodes(i, mp[cur-1], parent, size);
            }

            if(mp.count(cur+1)) {
                unionNodes(i, mp[cur+1], parent, size);
            }

            mx = max(mx, size[findParent(i, parent)]);
        }

        return mx;
    }
};