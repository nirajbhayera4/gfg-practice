/**
 * Problem Link : https://leetcode.com/problems/house-robber-ii/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int t[101];
    
    int solve(vector<int>& nums, int i, int n) {
        if (i > n)
            return 0;
        if(t[i]!=-1){
            return t[i];
        }

        int take = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);
        return t[i]=max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        memset(t,-1,sizeof(t));
        int take1 = solve(nums, 0, n - 2);
        memset(t,-1,sizeof(t));
        int take2 = solve(nums, 1, n - 1);
        return max(take1, take2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
