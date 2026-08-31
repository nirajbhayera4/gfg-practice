/**
 * Problem Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;
        vector<int> ans;

        // Count frequency of nums1
        for(int x : nums1) {
            freq[x]++;
        }

        // Check nums2
        for(int x : nums2) {

            if(freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
