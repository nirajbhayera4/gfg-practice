/**
 * Problem Link : https://leetcode.com/problems/min-cost-to-connect-all-points/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
typedef pair<int, int>p;
int PrimsAlgo(vector<vector<p>>&adj,int V){
    priority_queue<p, vector<p> , greater<p>>pq;
    pq.push({0,0});
    vector<bool> visited(V, false);
    int sum=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int wt=p.first;
        int node=p.second;
        if(visited[node]==true)continue;
        visited[node]=true;
        sum+=wt;
        for(auto &v : adj[node]){
            int neigh=v.first;
            int n_wt=v.second;
            if(visited[neigh]==false){
                pq.push({n_wt,neigh});
            }
        }
        
        
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<p>> adj(V);
        for(int i=0;i <V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
                


                

            }
            
        }
        return PrimsAlgo(adj, V);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
