#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void f(int i, vector<int>&vis, vector<vector<int>>& adj){
        if (vis.size()==adj.size())return;
        if (find(vis.begin(), vis.end(), i)==vis.end())vis.push_back(i);
        else return;
        for(int j=0; j<adj[i].size(); j++){
            f(adj[i][j], vis, adj);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis;
        f(0, vis, adj);
        return vis;
    }
};