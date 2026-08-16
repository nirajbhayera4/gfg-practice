/**
 * Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
int t[2501][2501];
int solve(vector<int> &nums, int idx, int p){
    if(idx >=n){
        return 0;

    }
    if(p !=-1 && t[idx][p]!=-1){
        return t[idx][p];
    }

    // take condition 
    int take=0;
    if(p ==-1 ||  nums[p] < nums[idx]){
        take=1 + solve(nums, idx+1, idx);
    }

    // skip ccondition 
    // if take nahi hoga to obv skiphi krega 
    int skip= solve(nums , idx +1 , p);
    if(p!=-1){
         t[idx][p]=max(take, skip);
    }
    return max(take, skip);


}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0,-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
