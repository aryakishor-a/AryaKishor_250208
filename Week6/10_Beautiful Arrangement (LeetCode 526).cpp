#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;

    void solve(int pos, int n, vector<int>&used) {
        if (pos>n) {
            ans++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (used[num]==0 && (num%pos == 0 || pos%num == 0)) {
                used[num]=1;
                solve(pos+1,n, used);
                used[num]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> used(n+1,0);
        solve(1,n,used);
        return ans;
    }
};