/**
 * Problem Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define p pair<int, int>
void dij(int n , unordered_map<int, vector<p>> adj, vector<int> &result, int s){
    priority_queue<p , vector<p> , greater<p>>pq;
    pq.push({0,s});
    fill(result.begin(), result.end(), INT_MAX);


    result[s]=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto & v : adj[node]){
            int adjnode=v.first;
            int dist=v.second;
            if(d + dist < result[adjnode]){
                result[adjnode]=d +dist;
                pq.push({d+dist, adjnode});
            }
        }
    }
    
}
int findcity(int n, vector<vector<int>>&SPM, int D){
    int resultcity=-1;
    int leastcount=INT_MAX;
    for(int i=0;i<n;i++){
        int countreach=0;
        for(int j=0;j<n;j++){
            if(1!=j && SPM[i][j]<=D){
                countreach++;
            }
        }
        if(countreach <=leastcount){
            leastcount=countreach;
            resultcity=i;
        }
    }
    return resultcity;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // vector banayenge jisme fill krenge 
        vector<vector<int>> SPM( n, vector<int> (n ,1e9+7));
        for(int i=0;i<n;i++){
            SPM[i][i]=0; // diagonals elements 0 se fill kr denge 

        }
        unordered_map<int, vector<p>> adj;
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            

        }

        // har ek index me DIJKSTRA's call kr denge 
        for(int i=0;i<n;i++){
            dij(n, adj, SPM[i], i);
        }
        return findcity(n, SPM, distanceThreshold);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
