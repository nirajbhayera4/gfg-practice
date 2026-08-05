/**
 * Problem Link : https://leetcode.com/problems/path-with-minimum-effort/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
typedef pair<int,pair<int, int>>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> result(m,vector<int> (n, INT_MAX));
        priority_queue<p, vector<p> , greater<p>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        auto isSafe=[&](int x,int y){
            return x >=0 && x<m && y>=0 && y<n;
        };
        while(!pq.empty()){
            int d=pq.top().first;
            auto cord=pq.top().second;
            int x=cord.first;
            int y=cord.second;
            pq.pop();
            for(auto & dir : directions){
                int x_=x + dir[0];
                int y_=y + dir[1];
                
                if(isSafe(x_, y_)){
                    int absdiff=abs(heights[x][y] - heights[x_][y_]);
                    int maxdiff=max(d, absdiff);
                    if(result[x_][y_]>  maxdiff){
                        result[x_][y_]=maxdiff;
                        pq.push({maxdiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
