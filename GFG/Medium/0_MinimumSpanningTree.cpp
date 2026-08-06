/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    int spanningTree(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<P>> adj(V);

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
    }
};
