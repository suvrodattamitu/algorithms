//https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/
#include<bits/stdc++.h>
using namespace std;

class SegTree {
public:
    vector<long long>tree;
    SegTree(int n) {
        tree.resize(4*n,0);
    }

    void update(int ind, int l, int r, int tar) {
        if(l > tar || r < tar) return;
        if(l == r) {
            tree[ind]++;
            return;
        }
        int m = l + (r - l) / 2;
        update(2*ind+1, l, m, tar);
        update(2*ind+2, m+1, r, tar);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }

    long long query(int ind, int l, int r, int low, int high) {
        if(l > high || r < low)return 0;
        if(low <= l and high >= r) {
            return tree[ind];
        }

        int m=l+(r-l)/2;
        return query(2*ind+1, l, m, low, high) + query(2*ind+2, m+1, r, low, high);
    } 
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> arr(n, 0);

        for(int i = 0; i < n; i++) {
            arr[i] = nums1[i] - nums2[i];
        }

        long long ans = 0;
        
        int top = 40000, add = 20000;
        auto pos = new SegTree(top);
        for(int i = 0; i < n; i++) {
            ans += pos->query(0, 0, top, 0, arr[i] + add + diff);
            pos->update(0, 0, top, arr[i] + add);
        }
        return ans;
    }
};