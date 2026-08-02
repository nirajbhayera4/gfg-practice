/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int>&ans){
      visited[u]=true;
      ans.push_back(u);
      for(auto &v : adj[u]){
          if(!visited[v]){
              DFS(v,adj, visited, ans);
          }
      }
  }

    vector<int> dfs( vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<bool> visited(V,false);
        
        vector<int> ans;
        DFS(0,adj, visited,ans);
        return ans;
        
    }
};
