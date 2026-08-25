/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &nums) {
        // Code here
        int curr=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i], curr + nums[i]);
            ans=max(ans,curr);
        }
        return ans;
    }
};
