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
void dij(int n,unordered_map<int , vector<p>> &adj,vector<int> &result, int s){
    priority_queue<p, vector<p> , greater<p>>pq;
    pq.push({0,s});
    // result vector ko fill kr denge INT_MAX  se 
    fill(result.begin(), result.end(), INT_MAX);
    result[s]=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto & v : adj[node]){
            int adjnode=v.first;
            int wt=v.second;
            if(d + wt < result[adjnode]){
                result[adjnode]=d+wt;
                pq.push({d+wt, adjnode});
            }
        }
    }

}
// esi city find krenge jiska distance threshold se kam ko

int findcity(int n , vector<vector<int>> &SPM,int D){
    int resultcity=-1;
    int leastcount=INT_MAX;
    for(int i=0;i<n;i++){
        int countreach=0;

        for(int j=0;j<n;j++){
            if(i !=j && SPM[i][j] <=D){
                countreach++;
                
            }
        }
        if(countreach <=leastcount){
            leastcount=countreach;
            resultcity=i;
        }
    }return resultcity;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int> (n,1e9 +7));
        for(int i=0;i<n;i++){
            SPM[i][i]=0;// diagonal elements ko fill kr dega 

        }
        // adj list -> because weighted and birectional graph hai 
        unordered_map<int , vector<p>> adj;
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            int wt= edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            
        }
        // har ke node ke liye dijsktra call krega and SPM matrix me bhar dega 
        for(int i=0;i < n;i++){
            dij(n, adj, SPM[i], i);

        }
        return findcity(n, SPM, distanceThreshold);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
