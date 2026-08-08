/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/factorial5739/1
 * Platform     : GFG
 * Difficulty   : Basic
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1005];

    int solve(int n) {
        if (n <= 1)
            return 1;

        if (t[n] != -1)
            return t[n];

         t[n] = n * solve(n - 1);

        return t[n];
    }

    int factorial(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
