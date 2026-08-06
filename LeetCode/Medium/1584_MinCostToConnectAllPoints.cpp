/**
 * Problem Link : https://leetcode.com/problems/min-cost-to-connect-all-points/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //typedef pair<int, int> p;
    /**
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
    */
    vector<int> parent, rank;
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp)
            return;
        if (rank[xp] > rank[yp]) {
            parent[yp] = xp;

        } else if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else {
            parent[xp] = yp;
            rank[yp]++;
        }
    }

    int kruskuls(vector<vector<int>>& adj) {
        int sum = 0;
        for (auto& temp : adj) {
            ;

            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            int parent_u = find(u);
            int parent_v = find(v);
            if (parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        vector<vector<int>> adj;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                adj.push_back({i, j, d});
            }
        }
        auto comprator = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(begin(adj), end(adj), comprator);
        return kruskuls(adj);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
