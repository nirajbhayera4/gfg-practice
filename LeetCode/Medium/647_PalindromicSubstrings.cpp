/**
 * Problem Link : https://leetcode.com/problems/palindromic-substrings/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1001][1001];

    bool check(string &s, int i, int j) {
        if (i >=j) {
            return true;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        // simple logic hai---> palindrome ke liye first and last index ko
        // inward move kro
        if (s[i] == s[j]) {
            return t[i][j] = check(s, i + 1, j - 1);
        }
        return t[i][j]=false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
