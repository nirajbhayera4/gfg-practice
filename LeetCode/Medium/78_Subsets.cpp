/**
 * Problem Link : https://leetcode.com/problems/subsets/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> result;
void backtrack(vector<int> &nums,int i, vector<int>&curr,vector<vector<int>>&result){
    if(i==nums.size()){
        result.push_back(curr);
        return ;
    }

    // take
    curr.push_back(nums[i]);
    backtrack(nums, i+1,curr, result);
    curr.pop_back();

    //skip 
    backtrack(nums,i+1,curr,result);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        int n=nums.size();
        backtrack(nums,0,curr,result);
        return result;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
