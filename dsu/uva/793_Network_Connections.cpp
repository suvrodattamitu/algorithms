// strange input and strange output
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=734
#include <bits/stdc++.h>
using namespace std;

int findParent(int i, int parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}

void unionNodes(int a, int b, int parent[], int size[])
//to merge the connected components of nodes a and b
{
    int parent_a = findParent(a, parent);
    int parent_b = findParent(b, parent);
    
    if(parent_a == parent_b) // they are already friends
        return;
        
    if(size[parent_a] >= size[parent_b])//the larger connected component eats up the smaller one
    {
        size[parent_a]     += size[parent_b];
        parent[parent_b]   = parent_a;
    }
    
    else
    {
        size[parent_b]  += size[parent_a];
        parent[parent_a] = parent_b;
    }
    
    return;
}

int main() {
    int test, n, succ, unsucc, x, y;
    string str;
    cin >> test;
    for(int t=0; t<test; t++) {
        cin >> n;
        
        int parent[n+1] = {1}, size[n+1] = {1};
        for(int i = 1; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1;
        }
        
        succ = unsucc = 0;
        cin.ignore();
        char c;
        while(getline(cin, str) && str.size()) {
            sscanf(str.c_str(),"%c %d %d",&c,&x,&y);
            if(c == 'c') {
                unionNodes(x, y, parent, size);
            } else {
                int a_parent = findParent(x, parent);
                int b_parent = findParent(y, parent);
                
                if(a_parent == b_parent) succ++;
                else unsucc++;
            }
        }
        
        if(t)
            puts("");
        printf("%d,%d\n", succ, unsucc);
    }
    return 0;
}