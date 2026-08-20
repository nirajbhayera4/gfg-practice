/**
 * Problem Link : https://leetcode.com/problems/subsets-ii/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& nums, int i,
                   vector<int>& curr,
                   vector<vector<int>>& result) {

        result.push_back(curr);

        for(int j = i; j < nums.size(); j++) {

            // Skip duplicate choices at the same level
            if(j > i && nums[j] == nums[j - 1])
                continue;

            curr.push_back(nums[j]);

            backtrack(nums, j + 1, curr, result);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> curr;

        backtrack(nums, 0, curr, result);

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
