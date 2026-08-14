/**
 * Problem Link : https://leetcode.com/problems/unique-paths-iii/
 * Platform     : LeetCode
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int result;
    int nonobs;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void backtrack(vector<vector<int>>& grid, int count, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) {
            return;
        }

        if (grid[i][j] == 2) {
            if (count == nonobs)
                result++;

            return;
        }

        grid[i][j] = -1;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            backtrack(grid, count + 1, i_, j_);
        }
        grid[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        result = 0;
        nonobs = 0;
        int start_x = 0, start_y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]!=-1) {
                    nonobs++;
                }
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
           
        }
        
        int count = 1;
        backtrack(grid, count, start_x, start_y);
        return result;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
