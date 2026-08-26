/**
 * Problem Link : https://leetcode.com/problems/move-zeroes/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0;

        // Put all non-zero elements at the front
        for(int j = 0; j < nums.size(); j++) {

            if(nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }

        // Fill remaining positions with zero
        while(i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
