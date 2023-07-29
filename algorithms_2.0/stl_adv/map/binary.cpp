//https://leetcode.com/problems/snapshot-array/description/
#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    map<int, map<int, int>> arr;
    int totalCalled = 0;
    SnapshotArray(int length) {
    
    }
    
    void set(int index, int val) {
        arr[index][totalCalled] = val;
    }
    
    int snap() {
        totalCalled++;
        return totalCalled - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        return it == begin(arr[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */