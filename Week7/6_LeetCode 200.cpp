#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void isl(int i, int j, vector<vector<char>>& grid, vector<vector<int>>&visited){
        if (i>=grid.size()||i<0||j>=grid[0].size()||j<0)return;
        if(grid[i][j]=='0'||visited[i][j]==1)return;
        visited[i][j]=1;

        isl(i+1,j,grid,visited);
        isl(i-1,j,grid,visited);
        isl(i,j+1,grid,visited);
        isl(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j]=='1'&&visited[i][j]==0){
                    ans++;
                    isl(i,j, grid,visited);
                }
            }
        }
        return ans;
    }
};