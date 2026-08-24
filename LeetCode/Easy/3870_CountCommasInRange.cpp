/**
 * Problem Link : https://leetcode.com/problems/count-commas-in-range/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int ans = 0 ; 
        for( int i = 1 ; i <= n; i++ ) {
            int d = to_string(i).size() ; 
            ans += ( d - 1 ) / 3 ; 
        }
        return ans ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
