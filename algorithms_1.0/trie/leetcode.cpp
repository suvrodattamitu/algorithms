//https://leetcode.com/problems/implement-trie-prefix-tree/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Trie {
public:
    Trie* child[26];
    bool isWordCompleted;
    Trie() {
        isWordCompleted = false;
        rep0(i, 26) {
            child[i] = NULL;
        }
    }
    
    void insert(string word) {
        Trie *curr = this;
        rep0(i, len(word)) {
            int id = word[i]-'a';
            if (!curr -> child[id])
                curr -> child[id] = new Trie();
            curr = curr -> child[id];
        }
        curr->isWordCompleted = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        rep0(i, len(word)) {
            int id = word[i] - 'a';
            if (curr->child[id] == NULL)
                return false;
            curr = curr->child[id];
        }

        return curr->isWordCompleted;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */