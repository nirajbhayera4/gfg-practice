/**
 * Problem Link : https://leetcode.com/problems/word-search/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool find(vector<vector<char>>& grid, int i, int j, int idx, string& word) {
        if (idx == word.length()) {
            return true; // means idx last word tak pahuch gya hai
        }

        if(i <0 || j<0 || i>=n || j>=m || grid[i][j]=='$'){
            return false;
        }
        if(grid[i][j]!=word[idx])return false;

        char temp=grid[i][j];
        grid[i][j]='$';

        for(auto &dir : directions){
            int i_=i + dir[0];
            int j_=j + dir[1];
            if(find(grid, i_, j_, idx+1, word))return true;
        }
        // backtrack krke value wapis assign krdo 
        grid[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& grid, string word) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0] && find(grid, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
