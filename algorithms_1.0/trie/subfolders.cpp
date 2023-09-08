//https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define repch(ch, n) for(char ch = 'a'; ch <= n; ch++)
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

struct Node {
    Node* child[27];           // 0-25 alphabet 26 = '/'
    bool isWordCompleted = false;
    string word;

    bool isContains(char ch) {       // Node has ch or not
        return child[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* node) {
        child[ch-'a'] = node;
    }

    Node* get(char ch) {
        return child[ch-'a'];
    }
};

class Trie {
public: 
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        rep0(i, len(word)) {
            char ch = word[i];
            if(ch == '/') ch = 'z' + 1;

            if(!(node->isContains(ch)))
                node->put(ch, new Node());
            node = node->get(ch);
        }

        char ch = 'z' + 1; 
        node->put(ch, new Node());
        node = node->get(ch);
        node->isWordCompleted = true;
        node->word = word;
    }

    void searchAll(Node* root, vector<string>& ans) {
        if(root == NULL) return;
        if(root->isWordCompleted) {
            ans.pb(root->word);
            return;
        }

        repch(ch, 'z'+1) {
            if (root->isContains(ch)) {
                searchAll(root->get(ch), ans);
            }
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        Trie trie;
        for(string folder : folders) {
            trie.insert(folder);
        }

        vector<string> ans;
        trie.searchAll(trie.root, ans);
        return ans;
    }
};