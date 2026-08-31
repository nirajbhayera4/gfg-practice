/**
 * Problem Link : https://leetcode.com/problems/intersection-of-two-arrays/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> ans;
        for(int x : nums1){
            st.insert(x);


        }

        for(int x : nums2){
            if(st.count(x)){
                ans.push_back(x);
                st.erase(x);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
