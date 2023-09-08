//https://leetcode.com/problems/search-suggestions-system/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a))
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
const ll maxn = 2e5;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

class Trie {
public: 
    Trie* child[26];
    bool isWordCompleted;
    string word;
    Trie() {
        isWordCompleted = false;
        word = "";
        rep0(i, 26) {
            child[i] = NULL;
        }
    }

    void insert(string word) {
        Trie* root = this;
        rep0(i, len(word)) {
            int id = word[i]-'a';
            if (!root -> child[id])
                root -> child[id] = new Trie();
            root = root -> child[id];
        }

        root->isWordCompleted = true;
        root->word = word;
    }

    bool search(string word) {
        Trie* root = this;
        rep0(i, len(word)) {
            int id = word[i] - 'a';
            if (root->child[id] == NULL)
                return false;
            root = root->child[id];
        }

        return root->isWordCompleted;
    }

    void searchAllWords(string partial, int& count, vector<string>& cur) {
        Trie* root = this;
        
        if(count > 2) return;
        if(root->isWordCompleted) {
            cur.pb(partial);
            count++;
        }
        
        rep0(i, 26) {
            if(root->child[i] != NULL) {
                partial += (i + 'a');
                root->child[i]->searchAllWords(partial, count, cur);
                partial.pop_back();
            }
        }
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        rep0(i, len(prefix)) {
            int id = prefix[i] - 'a';
            if (curr->child[id] == NULL)
                return false;
            curr = curr->child[id];
        }

        return true;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for(string product : products) {
            root->insert(product);
        }

        vector<vector<string>> ans;
        int n = searchWord.size();

        string partial = "";
        for(int i = 0; i < n; i++) {
            char ch = searchWord[i];
            if(root->child[ch - 'a'] == NULL) {
                while(i < n) {
                    ans.push_back({});
                    i++;
                }    
            } else {
                partial += ch;

                vector<string> cur;
                root = root->child[ch - 'a'];
                //search all words with this prefix
                int count = 0;
                root->searchAllWords(partial, count, cur);
                ans.pb(cur);
            }
        }

        return ans;
    }
};