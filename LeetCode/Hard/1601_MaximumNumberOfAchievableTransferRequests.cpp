/**
 * Problem Link : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
 * Platform     : LeetCode
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0;
    int m;

    void solve(int idx, int count, vector<int>& resultant,
               vector<vector<int>>& requests) {

        // All requests considered
        if (idx >= requests.size()) {
            for (int x : resultant) {
                if (x != 0)
                    return;
            }

            result = max(result, count);
            return;
        }

        // Take the current request
        int from = requests[idx][0];
        int to = requests[idx][1];

        resultant[from]--;
        resultant[to]++;

        solve(idx + 1, count + 1, resultant, requests);

        // Undo
        resultant[from]++;
        resultant[to]--;

        // Don't take the current request
        solve(idx + 1, count, resultant, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        result = 0;
        m = requests.size();

        vector<int> resultant(n, 0);

        solve(0, 0, resultant, requests);

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
