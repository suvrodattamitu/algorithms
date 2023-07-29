//https://leetcode.com/contest/weekly-contest-324/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int smallestValue(int n) {
        while(1) {
            int tmp = n, sum = 0;
            for(int i = 2; i*i <= tmp; i++)
            {
                if(tmp%i == 0) {
                    while(tmp%i == 0) {
                        tmp /= i;
                        sum += i;
                    }
                }
            }
            
            if(tmp > 1) sum += tmp;
            if(sum == n) return sum;
            
            n = sum;
        }
        return n;
    }
};