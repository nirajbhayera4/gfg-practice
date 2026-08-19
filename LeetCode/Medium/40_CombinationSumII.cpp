/**
 * Problem Link : https://leetcode.com/problems/combination-sum-ii/
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

        // same recursion level pe duplicates ko remove kr denge 
        if( j>i && candidates[j]==candidates[j-1]){
            continue;
        }
        curr.push_back(candidates[j]);
        backtrack(candidates,target - candidates[j], j+1,curr);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<int> curr;
        backtrack(candidates, target, 0,curr);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
