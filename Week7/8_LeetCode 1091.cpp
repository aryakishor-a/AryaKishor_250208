#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0]=1;
        int directions[8][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };

        while (!q.empty()) {
            int i =q.front()[0];
            int j=q.front()[1];
            int len=q.front()[2];
            q.pop();

            if (i==n-1 && j==n-1)
                return len;

            for (int k=0;k<8; k++) {
                int ni=i+directions[k][0];
                int nj=j+ directions[k][1];

                if (ni>=0 && ni<n &&
                    nj>=0 && nj<n &&
                    grid[ni][nj]== 0) {

                    grid[ni][nj]=1;
                    q.push({ni, nj, len + 1});
                }
            }
        }
        return -1;
    }
};