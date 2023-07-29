//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> arr;
    void makeArr(ListNode* head) {
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* createBinarySearchTree(TreeNode* root, int start, int end) {
        if(start > end) return NULL;
        int mid = (start+end) / 2;

        root = new TreeNode(arr[mid]);
        root->left = createBinarySearchTree(root->left, start, mid-1);
        root->right = createBinarySearchTree(root->right, mid+1, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        makeArr(head);

        TreeNode* root = NULL;
        return createBinarySearchTree(root, 0, arr.size()-1);
    }
};