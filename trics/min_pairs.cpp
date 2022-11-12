//https://leetcode.com/contest/weekly-contest-317/problems/most-popular-video-creator/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long> vcnt;
        map<string, pair<long long, string>> vbest;
        
        for (int i = 0; i < ids.size(); i++) {
            vcnt[creators[i]] += views[i];
            pair<long long, string> vid = {-views[i], ids[i]};
            if (vbest.find(creators[i]) == vbest.end()) vbest[creators[i]] = vid;
            else vbest[creators[i]] = min(vbest[creators[i]] , vid);
        }
        
        vector<vector<string>> a;
        long long abest = 0;
        for (pair<string, long long> x: vcnt) {
            abest = max(abest, x.second);
        }
        for (pair<string, long long> x: vcnt) {
            if (x.second == abest) {
                vector<string> xx = {x.first, vbest[x.first].second};
                a.push_back(xx);
            }
        }
        return a;
    }
};