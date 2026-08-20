/**
 * Problem Link : https://leetcode.com/problems/permutations-ii/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
vector<vector<int>> result;
void backtrack(vector<int> &nums, vector<int> &curr, vector<vector<int>> &result,vector<bool> &used){
    if(curr.size()==nums.size()){
        result.push_back(curr);
        return ;
    }

    for(int j=0;j<nums.size();j++){
         if(used[j]) {
                continue;
            }
        if(j > 0 && nums[j] == nums[j-1] && !used[j-1])
    continue;

        curr.push_back(nums[j]);
        used[j]=true;
        backtrack(nums,curr, result,used);
        curr.pop_back();
        used[j]=false;
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> used(n, false);
        backtrack(nums, curr, result, used);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
