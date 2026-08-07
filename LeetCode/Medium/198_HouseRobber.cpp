/**
 * Problem Link : https://leetcode.com/problems/house-robber/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0; // dp[i-2];
        int prev1=0; // dp[i-1];

        for(int num: nums){
            int curr=max(prev1, prev2 + num);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
