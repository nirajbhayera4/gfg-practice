/**
 * Problem Link : https://leetcode.com/problems/valid-digit-number/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        int c=0,f=0;
        while(n){
            if(n<10 and n!=x) f=1;
            int d = n%10;
            if(d==x) c++;
            n/=10;
        }
        return c and f;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
