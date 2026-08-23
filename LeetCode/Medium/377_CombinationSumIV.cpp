/**
 * Problem Link : https://leetcode.com/problems/combination-sum-iv/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int backtrack(vector<int> &nums, int target,vector<int> &dp){
    // valid combo 

    if(target==0){
        return 1;
    }

    // invalid combo 
    if(target <0){
        return 0;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int count=0;


    for(int i=0;i<nums.size();i++){
        count+=backtrack(nums, target -nums[i], dp);

    }
    return count;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return backtrack(nums, target,dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
