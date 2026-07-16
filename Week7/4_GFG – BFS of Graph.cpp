#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> ans;
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};