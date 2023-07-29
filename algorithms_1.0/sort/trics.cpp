//sort on second
//https://leetcode.com/contest/weekly-contest-312/problems/sort-the-people
class Solution{
  public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights){
    int i;
    int n = names.size();
    vector<pair<int,string>> tmp;
    for(i=(0);i<(names.size());i++){
      tmp.push_back({-heights[i], names[i]});
    }
    sort(tmp.begin(), tmp.end());
    for(i=(0);i<(n);i++){
      names[i] = tmp[i].second;
    }
    return names;
  }
}
;