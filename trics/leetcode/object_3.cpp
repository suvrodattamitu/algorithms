//https://leetcode.com/contest/weekly-contest-303/problems/design-a-food-rating-system/
class FoodRatings {
public:
    map<string, string> C;
    map<string, int> R;
    map<string,set<pair<int,string>>> S;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        S.clear();
        R.clear();
        C.clear();
        for(int i = 0; i < foods.size(); i++) {
            C[foods[i]] = cuisines[i];
            R[foods[i]] = ratings[i];
            S[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        if(C.count(food) == 0) return;
        S[C[food]].erase({-R[food], food});
        R[food] = newRating;
        S[C[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return S[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */