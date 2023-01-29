#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> algos = {
        "dfs/bfs", 
        "binary_search", 
        "tree", 
        "sliding_window", 
        "dp/recursion/backtrack", 
        "bit", 
        "z_algorithm and trie", 
        "segment_tree", 
        "dsu/kruskal", //https://atcoder.jp/contests/abc235/tasks/abc235_e
        "floyd warshal"
    };

    srand((unsigned) time(NULL));
    int idx = (rand() % (algos.size()));
    cout << algos[idx] << endl;
}

//shortest path in a grid bfs
//must do dps : https://leetcode.com/list/50wroh7h/