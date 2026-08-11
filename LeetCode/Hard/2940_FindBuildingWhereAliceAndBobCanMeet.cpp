/**
 * Problem Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/
 * Platform     : LeetCode
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int* construct(vector<int>& heights, int n) {
        int* seg = new int[4 * n];

        build(0, 0, n - 1, seg, heights);

        return seg;
    }

    void build(int i, int l, int r, int seg[], vector<int>& heights) {

        if (l == r) {
            seg[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, seg, heights);
        build(2 * i + 2, mid + 1, r, seg, heights);

        int leftidx = seg[2 * i + 1];
        int rightidx = seg[2 * i + 2];

        // Store index having maximum height
        if (heights[leftidx] >= heights[rightidx]) {
            seg[i] = leftidx;
        }
        else {
            seg[i] = rightidx;
        }
    }

    int query(int start, int end,
              int i, int l, int r,
              int seg[], vector<int>& heights) {

        // Completely outside
        if (l > end || r < start) {
            return -1;
        }

        // Completely inside
        if (l >= start && r <= end) {
            return seg[i];
        }

        int mid = l + (r - l) / 2;

        int leftidx = query(start, end,
                            2 * i + 1, l, mid,
                            seg, heights);

        int rightidx = query(start, end,
                             2 * i + 2, mid + 1, r,
                             seg, heights);

        if (leftidx == -1)
            return rightidx;

        if (rightidx == -1)
            return leftidx;

        if (heights[leftidx] >= heights[rightidx])
            return leftidx;

        return rightidx;
    }

    int RMIQ(int seg[], vector<int>& heights,
             int n, int l, int r) {

        return query(l, r, 0, 0, n - 1, seg, heights);
    }

    vector<int> leftmostBuildingQueries(
        vector<int>& heights,
        vector<vector<int>>& queries) {

        int n = heights.size();

        int* seg = construct(heights, n);

        vector<int> ans;

        for (auto& q : queries) {

            int minidx = min(q[0], q[1]);
            int maxidx = max(q[0], q[1]);

            // Same building
            if (minidx == maxidx) {
                ans.push_back(minidx);
                continue;
            }

            // maxidx can directly reach
            if (heights[maxidx] > heights[minidx]) {
                ans.push_back(maxidx);
                continue;
            }

            int threshold =
                max(heights[minidx], heights[maxidx]);

            int l = maxidx + 1;
            int r = n - 1;

            // No buildings after maxidx
            if (l > r) {
                ans.push_back(-1);
                continue;
            }

            // First check whether ANY valid building exists
            int idx = RMIQ(seg, heights, n, l, r);

            if (heights[idx] <= threshold) {
                ans.push_back(-1);
                continue;
            }

            // Binary search for leftmost valid index
            while (l < r) {

                int mid = l + (r - l) / 2;

                int idx = RMIQ(seg, heights, n, l, mid);

                if (heights[idx] > threshold) {
                    // A valid building exists in [l, mid]
                    r = mid;
                }
                else {
                    // No valid building in [l, mid]
                    l = mid + 1;
                }
            }

            ans.push_back(l);
        }

        delete[] seg;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
