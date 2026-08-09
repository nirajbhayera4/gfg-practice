/**
 * Problem Link : https://leetcode.com/problems/range-sum-query-mutable/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> seg;
    int n;
    void build(int i, int l, int r, vector<int>& nums) {
        // Leaf node
        if (l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    void updatetree(int i, int l, int r, int idx, int val) {

        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updatetree(2 * i + 1, l, mid, idx,
                       val); // left tree me search kreega
        } else {
            updatetree(2 * i + 2, mid + 1, r, idx,
                       val); // right tree me search krega
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int query(int i, int l, int r, int start, int end) {
        // case 1 : out of bound

        if (l > end || r < start) {
            return 0;
        }

        // case 2: completely range ke andar hoga
        if (l >= start && r <= end) {
            return seg[i];
        }
        int mid = l + (r - l) / 2;

        // case 3 : if partially range ke andar hoga
        return query(2 * i + 1, l, mid, start, end) +
               query(2 * i + 2, mid + 1, r, start, end);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        if (n > 1) {
            build(0, 0, n - 1, nums);
        }
    }

    void update(int index, int val) { updatetree(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
