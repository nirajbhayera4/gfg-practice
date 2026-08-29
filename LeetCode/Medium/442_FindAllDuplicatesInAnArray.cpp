/**
 * Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int x : nums){
            freq[x]++;
        }

        for(auto it : freq){
            if(it.second ==2){
                ans.push_back(it.first);

            }
        }
        return ans;

        
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
