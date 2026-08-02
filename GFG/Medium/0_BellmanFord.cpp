/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int s) {
        // Code here
        vector<int> result(V, 1e8);
        result[s]=0;// src ka distance 0 hi hoga isliye 0 push kr denge 
        for(int cnt=1;cnt <=V -1;cnt++){
            for(auto & a : edges){
                int u=a[0];
                int v=a[1];
                int wt =a[2];
                
                if(result[u]!=1e8 && result[u] + wt < result[v]){
                    result[v]=result[u]+ wt;
                    
                }
            }
        }
        for(auto & a : edges){
                int u=a[0];
                int v=a[1];
                int wt =a[2];
                
                if(result[u]!=1e8 && result[u] + wt < result[v]){
                    return {-1};
                }
            }
        return result;
        
    }
};

