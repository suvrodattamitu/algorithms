/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start

// Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> arr1, arr2;
        while(l1->val) {
            arr1.push_back(l1->val);
        }

        while(l2->val) {
            arr2.push_back(l1->val);
        }

        if(arr1.size() < arr2.size()) swap(arr1, arr2);

        ListNode* arr = new ListNode();
        for(int i = 0; i < arr1.size(); i++) {
            int a = 0, b = 0, sum = 0;
            a = arr1[i];
            b = arr2[i];
            sum = a+b;
            arr->val = sum;
        }

        ListNode* arr = new ListNode();
        for(int val : arr1) {
            arr->val = val;
            cout << val << " ";
        }

        return arr;
    }
};
// @lc code=end

