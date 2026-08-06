/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> parent;
vector<int> rank;

int find(int i){
    if(parent[i]==i)return i;
    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp)return;
    
    if(rank[xp]> rank[yp]){
        parent[yp]=xp;
    }
    else if(rank[xp] < rank[yp]){
        parent[xp]=yp;
    }
    else {
        parent[xp]=yp;
        rank[yp]++;
    }
}
   // typedef pair<int, int> P;
   int kruskuls(vector<vector<int>> &vec){
       int sum=0;
       for(auto & temp: vec){
           int u=temp[0];
           int v=temp[1];
           int wt=temp[2];
           
           int parent_u=find(u);
           int parent_v=find(v);
           if(parent_u !=parent_v){
               Union(u,v);
               sum+=wt;
           }
       }
       return sum;
   }

    int spanningTree(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        /*vector<vector<P>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> vis(V, false);

        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int wt = curr.first;
            int node = curr.second;

            if (vis[node])
                continue;

            vis[node] = true;
            sum += wt;

            for (auto &it : adj[node]) {
                int neigh = it.first;
                int edgeWt = it.second;

                if (!vis[neigh]) {
                    pq.push({edgeWt, neigh});
                }
            }
        }

        return sum;
        */
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        
        auto comprator=[&](vector<int>&v1, vector<int> &v2){
            return v1[2]< v2[2];
            
        };
        
        sort(begin(edges), end(edges), comprator);
        return kruskuls(edges);
        
    }
    
};
