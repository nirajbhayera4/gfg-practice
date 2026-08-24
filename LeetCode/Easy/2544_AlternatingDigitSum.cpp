/**
 * Problem Link : https://leetcode.com/problems/alternating-digit-sum/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int cnt = 0, sum = 0, divi;

        while (n > 0) {
            divi = n % 10;
            cnt++;

            if (cnt % 2 == 0) {
                sum -= divi;
            } else {
                sum += divi;
            }

            n /= 10;
        }

        if (cnt % 2 == 0)
            return sum * (-1);

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
