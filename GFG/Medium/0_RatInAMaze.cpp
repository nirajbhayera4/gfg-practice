/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        string path = "";
        
        if (maze[0][0] == 1) // start only if valid
            solve(0, 0, maze, n, path);
             sort(result.begin(), result.end());
        
        return result;
    }

    void solve(int i, int j, vector<vector<int>> &maze, int n, string &path) {
        // base case
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        if (!isSafe(i, j, maze, n)) return;

        // mark visited
        maze[i][j] = 0;

        // LEFT
        path.push_back('L');
        solve(i, j - 1, maze, n, path);
        path.pop_back();

        // RIGHT
        path.push_back('R');
        solve(i, j + 1, maze, n, path);
        path.pop_back();

        // DOWN
        path.push_back('D');
        solve(i + 1, j, maze, n, path);
        path.pop_back();

        // UP
        path.push_back('U');
        solve(i - 1, j, maze, n, path);
        path.pop_back();

        // backtrack
        maze[i][j] = 1;
    }

    bool isSafe(int i, int j, vector<vector<int>> &maze, int n) {
        return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
    }
};
