class Solution {
public:    
    void build(int st[], vector<int> &arr, int node, int lo, int hi) {
        if(lo == hi) {
            st[node] = arr[lo];
            return;
        }

        int mid = lo + (hi-lo)/2, left = 2*node+1, right = 2*node+2;
        
        build(st, arr, left, lo, mid);
        build(st, arr, right, mid+1, hi);

        st[node] = st[left] ^ st[right]; 
    }

    int query(int st[], int node, int lo, int hi, int qlo, int qhi) {
        if(hi < qlo || lo > qhi)
            return 0;

        if(qlo <= lo && qhi >= hi)
            return st[node];

        int mid = lo + (hi-lo)/2, left = 2*node+1, right = 2*node+2;
        
        int l1 = query(st, left, lo, mid, qlo, qhi);
        int l2 = query(st, right, mid+1, hi, qlo, qhi);
        
        return l1 ^ l2;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int tree[4*n];
        
        build(tree, arr, 0, 0, n-1);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(query(tree, 0, 0, n-1, queries[i][0], queries[i][1]));
        }
        return ans;
    }
};


//https://leetcode.com/problems/handling-sum-queries-after-update/solutions/3204818/c-solution-segment-tree-lazy-propagation/
//https://leetcode.com/problems/handling-sum-queries-after-update/solutions/3202267/segment-tree-lazy-propagation-toggle-bits-concept-c-clean-code/