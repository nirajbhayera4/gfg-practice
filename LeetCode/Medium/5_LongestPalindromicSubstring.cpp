/**
 * Problem Link : https://leetcode.com/problems/longest-palindromic-substring/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 1;
        for (int i = 0; i < n; i++) {
            // odd size ke liye
            expandaroundcenter(s, i, i, start, maxlen);

            // even size ke liye
            expandaroundcenter(s, i, i + 1, start, maxlen);
        }
        return s.substr(start, maxlen);
    }

private:
    void expandaroundcenter(const string& s, int l, int r, int& start,
                            int& maxlen) {
        int n = s.size();
        while (l >= 0 & r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        int len =r-l - 1;

        if (len > maxlen) {
            maxlen = len;
            start = l + 1;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
