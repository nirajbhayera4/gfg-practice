/**
 * Problem Link : https://leetcode.com/problems/combination-sum/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> result;
void backtrack(vector<int> &candidates, int target, int i, vector<int> &curr){
    // if target 0 ke equal hogya 
    if(target==0){
        result.push_back(curr);
        return ;
    }

    // no comibation  found 
    if(target < 0 || i==candidates.size()){
        return ;
    }
    for(int j=i;j<candidates.size();j++){
        curr.push_back(candidates[j]);
        backtrack(candidates,target - candidates[j], j,curr);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, 0,curr);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
