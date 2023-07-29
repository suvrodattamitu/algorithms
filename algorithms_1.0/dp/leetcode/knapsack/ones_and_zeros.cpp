//https://leetcode.com/problems/ones-and-zeroes/description/?envType=study-plan-v2&id=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[601][101][101];
    //count the number of ones and zeroes present in the string.
    pair<int, int> countOneAndZero(string s) {
        int one = 0, zero = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') one++;
            else zero++;
        }
        
        return {zero, one};
    }

    int rec(int idx, int cnt_zeros, int cnt_ones, int& mx_zeros, int& mx_ones, vector<string>& arr) {
        // if ith index crosses the length then return 0
        if(idx >= arr.size()) return 0;

        // if any of the count, crosses the criteria of having maximum one or zero, then return 0
        if(cnt_zeros > mx_zeros || cnt_ones > mx_ones) return 0;

        if(dp[idx][cnt_zeros][cnt_ones] != -1) return dp[idx][cnt_zeros][cnt_ones];

        auto p = countOneAndZero(arr[idx]);

        int not_take = rec(idx + 1, cnt_zeros, cnt_ones, mx_zeros, mx_ones, arr);

        int take = 0;
        if(cnt_zeros + p.first <= mx_zeros && cnt_ones + p.second <= mx_ones) {
            take = 1 + rec(idx + 1, cnt_zeros + p.first, cnt_ones + p.second, mx_zeros, mx_ones, arr);
        }

        return dp[idx][cnt_zeros][cnt_ones] = max(not_take, take);
    }

    int findMaxForm(vector<string>& arr, int m, int n) {
        int mx_zeros = m;
        int mx_ones = n;

        memset(dp, -1, sizeof(dp));
        int ans = rec(0, 0, 0, mx_zeros, mx_ones, arr); // 'idx', count of zeros, count of ones, maxZero, maxOne, arr
        return ans;
    }
};