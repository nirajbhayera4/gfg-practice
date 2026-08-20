/**
 * Problem Link : https://leetcode.com/problems/permutations/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
vector<vector<int>> result;
void backtrack(vector<int> &nums, vector<int> &curr, vector<vector<int>> &result, vector<bool>&used){
    // base case :
    if(curr.size()==nums.size()){
        result.push_back(curr);
        return;
    }

    //2nd case:

    for(int j=0;j<nums.size();j++){
        // check if j is used  or not 
        if(used[j]==true){
            continue;
        }
        curr.push_back(nums[j]);
        //mark true krdo 
        used[j]=true;
        //backtrack recursive call
        backtrack(nums, curr, result, used);

        //wapis false mark krdo and pop back
        
        curr.pop_back();
        used[j]=false;
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> curr;
        vector<bool> used(n, false);
        backtrack(nums ,curr, result,used);
        return result;
    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
