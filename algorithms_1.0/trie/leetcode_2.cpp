//https://leetcode.com/problems/word-search-ii/description/
#include <bits/stdc++.h>
using namespace std;

#define rep0(i,n) for(int i = 0; i < n; i++)
#define len(x) ((int)x.size()) 
int dirs[4][4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

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
    set<string> res;
    void dfs(vector<vector<char>>& board,int i,int j,Trie* t,vector<vector<bool>>& visit) { 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return; //** dfs call to search for word
        char x = board[i][j]-'a';
        t = t->child[x];
        if(visit[i][j] || !t) return ;
    
        if(t->isWordCompleted) {
            res.insert((t->word));
        }

        visit[i][j] = true;
        dfs(board, i+1, j, t, visit);
        dfs(board, i-1, j, t, visit);
        dfs(board, i, j+1, t, visit);
        dfs(board, i, j-1, t, visit);
        visit[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(string word : words) {
            root->insert(word);
        }

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
               dfs(board, i, j, root, visit);
            }
        }

        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};