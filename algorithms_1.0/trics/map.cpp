#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,vector<string>> mp;
        for(auto word : words)
        {
            int k=word.size();
            vector<int> temp;
            for(int i=0;i<k-1;i++)
                temp.push_back(word[i+1]-word[i]);
            mp[temp].push_back(word);
        }
        
        for(auto &[diff,vec] : mp)
        {
            if(vec.size() == 1)
                return vec[0];
        }
        return "";
    }
};