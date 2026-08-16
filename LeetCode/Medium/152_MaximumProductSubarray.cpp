/**
 * Problem Link : https://leetcode.com/problems/maximum-product-subarray/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(vector<int> &nums){
    int n=nums.size();
    if(n==0)return 0;
    int curr_max=nums[0];
    int curr_min=nums[0];
    int res=nums[0];
    for(int i=1;i<n;i++){
        int temp=curr_max;
        curr_max=max({nums[i],temp * nums[i],curr_min * nums[i]});
        curr_min=min({nums[i],temp * nums[i],curr_min * nums[i]});
        res=max(res, curr_max);
        


    }
    return res;

}
    int maxProduct(vector<int>& nums) {
       
        return solve(nums);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
