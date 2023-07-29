//https://leetcode.com/problems/clone-graph/description/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            for(auto neighbor : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return mp[node];
    }
};