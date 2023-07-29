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

//https://usaco.guide/general/using-this-guide?lang=cpp

//shortest path in a grid bfs
//must do dps : https://leetcode.com/list/50wroh7h/

/*
Thanks, I have almost 4 years of Industrial experience in Vue Js. My project's backend is in using Laravel. But it takes just a few days to shift from one framework to another. It will take just a few days to cope with any new environment, We are developers, and our main task is to be flexible to work with any new technology for the company. I am a competitive programmer. So it would not be very hard for me to shift any language.I will prove my coding skill if there has any opportunity for me. Please take a look at my coding skills, 1.LeetCode profile: https://leetcode.com/suvro_datta2.CodeChef Profile: https://www.codechef.com/users/suvro_datta
*/
