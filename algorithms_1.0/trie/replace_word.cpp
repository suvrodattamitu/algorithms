//https://leetcode.com/problems/replace-words/description/
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
    Node* child[26];          
    bool isWordCompleted = false;
    string word;

    bool isContains(char ch) { 
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
            if(!(node->isContains(ch)))
                node->put(ch, new Node());
            node = node->get(ch);
        }

        node->isWordCompleted = true;
        node->word = word;
    }

    string findFirst(Node* root, string word) {
        rep0(i, len(word)) {
            if (root->isContains(word[i])) {
                root = root->get(word[i]);
                if(root->isWordCompleted) {
                    return root->word;
                }
            } 

            else return word;
        }

        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word : dictionary) {
            trie.insert(word);
        }

        ll n = len(sentence);

        string word = "", ans = "";
        rep0(i, n) {
            word.pb(sentence[i]);
            if(sentence[i] == ' ' || i+1 == n) {
                if(sentence[i] == ' ') word.pop_back();
                string str = trie.findFirst(trie.root, word);
                if(sentence[i] == ' ') str.pb(' ');
                ans += str;
                word = "";
            }
        }

        return ans;
    }
};