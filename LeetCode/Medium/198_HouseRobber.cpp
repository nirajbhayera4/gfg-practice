/**
 * Problem Link : https://leetcode.com/problems/house-robber/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0; // dp[i-2];
        int prev1=0; // dp[i-1];

        for(int num: nums){
            int curr=max(prev1, prev2 + num); // curr= max(0,0+1)=1
        
            prev2=prev1;// prev2=0;
            prev1=curr; // prev1=1;

            // jab next num ke liye chalega 
            // curr=max(1,0+2)=2;
            //prev2=1;
            //prev1=2;

            // next num-> 3
            // curr=max(2,1+3)=4
            //prev2=2
            //prev1=4;

            // next num->1
            // curr=max(4,2+1)=4
            // prev2=4
            // prev1=curr=4
            // ouptut -> 4
        }
        return prev1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
