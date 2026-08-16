/**
 * Problem Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
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
    int count1=1, count2=1;

    if(p ==-1 ||  nums[p] < nums[idx]){
        take=1 + solve(nums, idx+1, idx);
        count1++;
    }

    // skip ccondition 
    // if take nahi hoga to obv skiphi krega 
    else{
        int skip= solve(nums , idx +1 , p);
        count2++;
    }
    if(p!=-1){
         t[idx][p]=max(count1, count2);
    }
    return max(count1, count2);


}
    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, -1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
